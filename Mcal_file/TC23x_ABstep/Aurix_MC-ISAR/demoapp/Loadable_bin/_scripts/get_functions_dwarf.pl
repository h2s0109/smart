#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2012)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : get_functions_dwarf.pl                                        **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.03.12                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This perl script generates the function list needed for    **
#*                 Demoapp                                                    **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* VS          Vinod Shankar                                                 **
#* HL          Heidt Laurent                                                 **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#* V0.0.2: 2012.03.12, VS  : Changed to generate a C file instead of H
#* V0.0.1: 2012.03.12, HL  : Initial version
#*
#******************************************************************************/
#use strict;
#use warnings;
#use Data::Dumper;

# path to template header , path to dwarf file, Test run Number
# Test run Number #1 -> Perl Script executed without elf file
# Test run Number #2 -> Perl Script executed with elf file
my ($gen_file_path,$temp_path,$test_run)=@ARGV;

my @dwarf_tab=();   # lines of dwarf file
my %dwarf_info=();  # hash of dwarf information

my %fct_info=();    # hash with rough function's information
my %type_h=();      # hash with needed variable types

my %fct_tab_h=();   # hash with function's information adapted to generate the table

my $param_in_str  = ''; # string for the parameter in tables

# string for the fct C table
my $fct_c_table_str   = "const DemoApp_AnyFctListType DemoApp_AllFctList[]=";
$fct_c_table_str     .="\n{\n";

my $fct_prototyp_str = ''; # string for the extern fct prototypes

my $header_str='';  # contain the header template and later on the generated header

# flush
$|=1;

&main();

################################################################################
#                                                                              #
#                          M  A  I  N                                          #
#                                                                              #
################################################################################
sub main()
{
#print "Generate list of function\n";
#print "read $temp_path\nwrite $gen_file_path\n\n";
	#print "Value sent is ".$test_run
	if($test_run eq '1') 
	{
		&gen_op_file_Only_Demoapp();	
	}
	else
	{
		# read the dwarf file and generate a table index with each line   => @dwarf_tab
		&read_input_file();
		# generate from @dwarf_tab the hash containing all dwarf info     => %dwarf_info
		&parse_input_data();
		
		# generate from %dwarf_info a hash containing
		# all fct and fct parameters (coded as dwarf index)               => %fct_info
		&get_fct_list();     
		                    
		# generate a list containing all variable type that are needed
		# to resolve the type of all input+output function's parameters   => %type_h
		&get_req_var_type();
		
		# generate a hash containing all information with size in byte 
		# and parameter name                                              => %fct_tab_h
		# generate a string as a C table for the compilation         => $fct_c_table_str
		&generate_fct_table_h();
		
		# remove fonctions that does not need to be printed out
		&remove_fct();      
		
		# generate a string as a C table for the compilation         => $fct_c_table_str
		&generate_fct_table_str();
		
		# generate a string with fct extern prototype               => $fct_prototyp_str
		&generate_fct_prototyp_str();
		
		# finally generate the output C file that will be compiled
		&generate_output_file();
	}
}

####################################################################
#
#    read input file
#
####################################################################
sub read_input_file()
{
  open (FILE,$temp_path) or die ("$!: \ncannot read $temp_path\n");
  {
  	#local $/;
  	@dwarf_tab=<FILE>;
    #print"read input\n";
  }
  close(FILE);
}

####################################################################
#
# generate a hash containing all information with size in byte 
# and parameter name                                              => %fct_tab_h
#
####################################################################
sub generate_fct_table_h()
{

  # first from the %fct_info from the dwarf info, 
  # generate a new hash containing info we need for generating the table
  foreach my $fct_name (keys(%fct_info))
  {
    # only take global function into account
    if (exists($fct_info{$fct_name}{'DW_AT_external'}) && !exists($fct_info{$fct_name}{'DW_AT_inline'}))
    {
      #my @one_fct_tab =($fct_name);
      $fct_tab_h{$fct_name}=();
      if (exists($fct_info{$fct_name}{'DW_AT_type'}))
      {
        my $var_type_id = $fct_info{$fct_name}{'DW_AT_type'};
        $var_type_id = $1 if ($var_type_id =~ /<0x(\w+)>/);
        my %var_type_info = get_type_name($var_type_id);
        #push(@one_fct_tab,$var_type_info{'var_type_name'});
        $fct_tab_h{$fct_name}{'return'}{'var_type_size'}=$var_type_info{'var_type_size'};
        $fct_tab_h{$fct_name}{'return'}{'var_type_name'}=$var_type_info{'var_type_name'};
        $fct_tab_h{$fct_name}{'return'}{'var_type_base_name'}=$var_type_info{'var_type_base_name'};
      }
      else
      {
        #push(@one_fct_tab,'0');
        $fct_tab_h{$fct_name}{'return'}{'var_type_size'}=0;
        $fct_tab_h{$fct_name}{'return'}{'var_type_name'}='void';
      } 
      if (exists($fct_info{$fct_name}{'VARS'}))
      {
        my @input_vars=();
        foreach my $var_name (keys(%{$fct_info{$fct_name}{'VARS'}}))
        {
          my $var_type_id = $fct_info{$fct_name}{'VARS'}{$var_name};
          $var_type_id = $1 if ($var_type_id =~ /<0x(\w+)>/);
          my %var_type_info = get_type_name($var_type_id);
          #push(@input_vars,[$var_name,$var_type_info{'var_type_name'},$var_type_info{'var_type_size'}]);          
          $fct_tab_h{$fct_name}{'input'}{$var_name}{'var_type_name'}=$var_type_info{'var_type_name'};
          $fct_tab_h{$fct_name}{'input'}{$var_name}{'var_type_size'}=$var_type_info{'var_type_size'};
          $fct_tab_h{$fct_name}{'input'}{$var_name}{'var_type_base_name'}=$var_type_info{'var_type_base_name'};
        }
        $fct_tab_h{$fct_name}{'input_order'}=$fct_info{$fct_name}{'VARS_ORDER'};
        #push(@one_fct_tab,@input_vars);
      }
      else
      {
        #push(@one_fct_tab,'0');
      } 
    
    }
    else
    {
      #print "$fct_name is local\n";
    }    

  }
}

####################################################################
#
# generate a string as a C table for the compilation         => $fct_c_table_str
#
####################################################################
sub generate_fct_table_str()
{
  my %stat_in_param_h=();
  #print Dumper \%fct_tab_h;
  my @fct_list = sort {lc($a) cmp lc($b)} (keys(%fct_tab_h)); 

  # generate the table
  foreach my $fct_name (@fct_list)
  {
    my $lc_fct_name   = lc($fct_name);
    my $str           = "{\"$lc_fct_name\",$fct_name,";
    my $str_comment   = "  /*";
    my $str_inpar     = '';
    my $str_inpar_tab = '';
    my $num_input_par = 0;
    $str .= " $fct_tab_h{$fct_name}{'return'}{'var_type_size'} , ";
    $str_comment .= " $fct_tab_h{$fct_name}{'return'}{'var_type_name'}";
    if (exists($fct_tab_h{$fct_name}{'input'}))
    {
      $num_input_par = keys(%{$fct_tab_h{$fct_name}{'input'}});
      print "  warning: function $fct_name has more than 4 input parameters and cannot be called by the DemoApp\n" if ($num_input_par > 4);
      $str_inpar_tab = "DemoApp_par_$fct_name";
      $str .= "$num_input_par, $str_inpar_tab";
      foreach my $order_num (sort {hex("$a") <=> hex("$b")} (keys(%{$fct_tab_h{$fct_name}{'input_order'}})))
      {
        my $var_name = $fct_tab_h{$fct_name}{'input_order'}{$order_num};
        $str_inpar .= "$fct_tab_h{$fct_name}{'input'}{$var_name}{'var_type_size'},";      
        $str_comment .= " , $fct_tab_h{$fct_name}{'input'}{$var_name}{'var_type_name'}($fct_tab_h{$fct_name}{'input'}{$var_name}{'var_type_base_name'})";
        $stat_in_param_h{$str_inpar}++;      
      }
    }
    else
    {
      $str .= "0, 0";
      $str_comment .= " , void";
    }
    if ($num_input_par > 0)
    {
      $str_inpar =~ s/,$//;
      $param_in_str .= "const uint8 $str_inpar_tab\[${num_input_par}\] = {${str_inpar}}; \\\n";      
    }

    $str_comment .= " */";

    $str .= "}";
    $str .= ", \\" if ($fct_name ne $fct_list[-1]);
    $fct_c_table_str .= "  ".$str."\n";     
  } 
  #print $fct_c_table_str;
  #print $param_in_str;
  #print "\ntypes of in parameters: ".keys(%stat_in_param_h)."\n";
  #foreach (sort(keys(%stat_in_param_h)))
  #{
  #  print "$_\t:$stat_in_param_h{$_}\n";
  #}
}

####################################################################
#
# generate a string as a C table for the compilation         => $fct_c_table_str
# all fct are defined as void-void
#
####################################################################
sub generate_fct_table_void_str()
{
  # generate the table
  my @fct_list = sort {lc($a) cmp lc($b)} (keys(%fct_tab_h)); 
  foreach my $fct_name (@fct_list)
  {
    my $lc_fct_name   = lc($fct_name);
    my $str           = "{\"$lc_fct_name\",$fct_name,0,0,0}";
    $str .= ", \\\n" if ($fct_name ne $fct_list[-1]);
    $fct_c_table_str .= $str;
  }

  $fct_c_table_str .= "\n";
}

####################################################################
#
# generate extern prototype for fct                         => $fct_prototyp_str
#
####################################################################
sub generate_fct_prototyp_str()
{
  # generate the table
  my @fct_list = sort {lc($a) cmp lc($b)} (keys(%fct_tab_h)); 
  foreach my $fct_name (@fct_list)
  {
    $fct_prototyp_str .= "extern void $fct_name(void);\n";  
  }

  $fct_prototyp_str .= "\n";
}

####################################################################
#
#  return the size in byte, the name and base name of a dwarf type id
#  safety limit on 10 cycle.
#
####################################################################
sub get_type_name()
{
  my $var_type_id = $_[0];
  my %var_type_info=();
  my $loop_cnt = 0;
  
  $var_type_info{'var_type_name'} = '';
  $var_type_info{'var_type_base_name'} = '';
  #print "\n=> base $var_type_id ";
  do
  {
    #print " $var_type_id ";
    get_type_name_exit($var_type_id,\%var_type_info);
    if ( ($var_type_info{'var_type_base_name'} eq '') || ($var_type_info{'var_type_name'} eq '') )
    {
      #print "$var_type_info{'var_type_base_name'}\n";
      #print "$var_type_info{'var_type_name'}\n";
      if (exists($type_h{$var_type_id}{'type_id'}))
      {
        $var_type_id = $type_h{$var_type_id}{'type_id'};
      }
      else
      {
        print "Error: no value found for $var_type_id, set var type to no_name and no_type\n";
        $var_type_info{'var_type_name'}='no_name';
        $var_type_info{'var_type_size'}='32';
        $loop_cnt = 10;
      }
    }
    else
    {
      $loop_cnt = 10;
    }
    $loop_cnt++;
  }
  while ($loop_cnt < 10);
    
  return (%var_type_info);
} 

####################################################################
#
# Gives information about the current parsed dwarf type id
#  Called by get_type_name()
#
####################################################################

sub get_type_name_exit()
{
  my $var_type_id = $_[0];
  my $var_type_info_ptr = $_[1];
  #print " get $var_type_id ";

  my %var_name_exit = (
                        'uint8'  => '8',
                        'uint16' => '16',
                        'uint32' => '32',
                        'sint8'  => '7',
                        'sint16' => '15',
                        'sint32' => '31',                                                                                                  
                      );

  my %var_type_exit = (
                        'DW_TAG_pointer_type'     => 'pointer',         # continue until the first NAME
                        'DW_TAG_structure_type'   => 'struct',     # only happen as pointer, only take the name no size 
                        'DW_TAG_base_type'        => 'basetype',
                        'DW_TAG_union_type'       => 'uniontype' , # return the size in byte and the NAME
                        'DW_TAG_enumeration_type' => 'enumtype' ,  # return the size in byte and the NAME
                        'DW_TAG_subroutine_type'  => 'subroutintype' ,  # only happen as pointer
                      );

  if ( (exists($type_h{$var_type_id}{'NAME'})) && ($var_type_info_ptr->{'var_type_name'} eq '') )
  {
    $var_type_info_ptr->{'var_type_name'} = $type_h{$var_type_id}{'NAME'};
  }  
  if ( (exists($type_h{$var_type_id}{'NAME'})) && (exists($var_name_exit{$type_h{$var_type_id}{'NAME'}})) && ($var_type_info_ptr->{'var_type_base_name'} eq '') )
  {
     $var_type_info_ptr->{'var_type_base_name'} = $type_h{$var_type_id}{'NAME'};
     $var_type_info_ptr->{'var_type_size'} = $var_name_exit{$type_h{$var_type_id}{'NAME'}};
  }
  elsif ( (exists($type_h{$var_type_id}{'type'})) && (exists($var_type_exit{$type_h{$var_type_id}{'type'}})) )
  {
    if($type_h{$var_type_id}{'type'} eq 'DW_TAG_pointer_type')
    {
     $var_type_info_ptr->{'var_type_base_name'} = 'pointer';
      # the check of the size must be done because TASKING is not giving the size of a pointer.
      # Hightec give the size
      if (exists($type_h{$var_type_id}{'DW_AT_byte_size'}))
      {
        $var_type_info_ptr->{'var_type_size'} = ($type_h{$var_type_id}{'DW_AT_byte_size'}*8)+1; # +1 to distinguish in C file between uint32 and pointers
      }
      else
      {
        $var_type_info_ptr->{'var_type_size'} = 33;
      }
    }
    elsif($type_h{$var_type_id}{'type'} eq 'DW_TAG_base_type')
    {
      my $var_type_encoding = $type_h{$var_type_id}{'DW_AT_encoding'};
      my $var_type_size = $type_h{$var_type_id}{'DW_AT_byte_size'}*8;
      $var_type_encoding = $1 if ($var_type_encoding =~ /\((\w)/); 
      $var_type_size-- if ($var_type_encoding =~ /^s/);

      $var_type_info_ptr->{'var_type_base_name'} .= $type_h{$var_type_id}{'NAME'};
      $var_type_info_ptr->{'var_type_size'} = $var_type_size if ($var_type_info_ptr->{'var_type_size'} eq '');
    }
    elsif($type_h{$var_type_id}{'type'} eq 'DW_TAG_enumeration_type')
    {
     $var_type_info_ptr->{'var_type_base_name'} = 'enumeration';
     $var_type_info_ptr->{'var_type_size'} = $type_h{$var_type_id}{'DW_AT_byte_size'}*8;
    }
    elsif($type_h{$var_type_id}{'type'} eq 'DW_TAG_subroutine_type')
    {
     $var_type_info_ptr->{'var_type_name'} = 'function';
    }
    elsif($type_h{$var_type_id}{'type'} eq 'DW_TAG_structure_type')
    {
     $var_type_info_ptr->{'var_type_base_name'} = 'structure' if ($var_type_info_ptr->{'var_type_base_name'} eq '');
     $var_type_info_ptr->{'var_type_size'} = $type_h{$var_type_id}{'DW_AT_byte_size'}*8 if ($var_type_info_ptr->{'var_type_size'} eq '');
     $var_type_info_ptr->{'var_type_id'} = $var_type_id;
     $var_type_info_ptr->{'var_type_name'} = 'structure' if ($var_type_info_ptr->{'var_type_name'} eq '');
    }

  }

}

####################################################################
#
# generate from @dwarf_tab the hash containing all dwarf info     => %dwarf_info
#
####################################################################
sub parse_input_data()
{

  my $dw_p = \%dwarf_info;
  my $act_level = -1;

  #print "=> Get DWARF information\n";  
  foreach my $dw_line (@dwarf_tab)
  {
    if($dw_line =~ /<(\w+)><(\w+)>:.*\((\w+)\)/)
    {
      my $new_level = $1;
      my $ref_num = $2;
      my $level_type = $3;
      if ($new_level > $act_level)
      {
        #print "child\n";
      }
      elsif($new_level < $act_level)
      {
        for (my $cnt=$act_level; $cnt>=$new_level;$cnt--)
        {
          $dw_p = $dw_p->{'parent'};
          #print "parent\n";
        }
      }
      else
      {
        $dw_p = $dw_p->{'parent'};
        #print "same\n";
      }
      $dw_p->{"$ref_num"}{'parent'}=$dw_p;
      $dw_p = $dw_p->{"$ref_num"};

      $dw_p->{'type'}=$level_type;
      $act_level = $new_level;         
    }
    elsif($dw_line =~ /<(\w+)>\s+(\w+)\s*:\s+(.+?)\s*$/)
    {
      my $ref_num = $1;
      my $ref_type = $2; 
      my $ref_content = $3;
      $dw_p->{$2}=$3;
    }
  } 

}

####################################################################
#
# generate from %dwarf_info a hash containing
# all fct and fct parameters (coded as dwarf index)               => %fct_info
#
####################################################################
sub get_fct_list()
{
  #print Dumper \%dwarf_info;
  #print "=> Get function names and parameters\n";
  %fct_info = get_fct_names(\%dwarf_info);
  #print "\n\nFCT result:\n";
  #print Dumper \%fct_info ;

}

####################################################################
#
# generate a list containing all variable type that are needed
# to resolve the type of all input+output function's parameters   => %type_h
#
####################################################################
sub get_req_var_type()
{  
  #print "=> Get required variables type\n";  
  %type_h = get_req_type();
  #print "\n\ntype required:\n";
  #print Dumper \%type_h ;

  $type_h{'status'} = '';
  my $cnt_resolve_type = 1;
  do
  {
    #print "\ntype resolving parse $cnt_resolve_type\n";
    $type_h{'status'}= 'resolved';
    resolve_req_type(\%dwarf_info,\%type_h);  
    #print "\nloop $cnt_resolve_type: status $type_h{'status'}\n";

    $cnt_resolve_type++
  }
  while ( ($cnt_resolve_type<10) && $type_h{'status'} ne 'resolved');
    
  #print Dumper \%type_h ;

}

####################################################################
#
# recursive fct to get the variable type of all requested types
#
####################################################################
sub resolve_req_type
{
  my $ptr_dwarf_h = $_[0];
  my $prt_types_h = $_[1];
 
  foreach (keys(%{$ptr_dwarf_h}))
  {
    my $act_k = $_;
    # parent shall not be parsed otherwise it goes back to upper level !
    if ($act_k ne 'parent')
    {
      # if the key is a requested type, get the information
      if (exists($prt_types_h->{$act_k}))
      {
        $prt_types_h->{$act_k}{'type'} = $ptr_dwarf_h->{$act_k}{'type'};
        if (exists($ptr_dwarf_h->{$act_k}{'DW_AT_name'}))
        {
          my $var_name = $ptr_dwarf_h->{$act_k}{'DW_AT_name'};
          $var_name = $1 if ($var_name =~ /^.*:\s+(\w+)/); 

          $prt_types_h->{$act_k}{'NAME'} = $var_name;         
        }
        if (exists($ptr_dwarf_h->{$act_k}{'DW_AT_byte_size'}))
        {
          $prt_types_h->{$act_k}{'DW_AT_byte_size'} = $ptr_dwarf_h->{$act_k}{'DW_AT_byte_size'};         
        }
        if (exists($ptr_dwarf_h->{$act_k}{'DW_AT_encoding'}))
        {
          $prt_types_h->{$act_k}{'DW_AT_encoding'} = $ptr_dwarf_h->{$act_k}{'DW_AT_encoding'};         
        }
        if (exists($ptr_dwarf_h->{$act_k}{'DW_AT_type'}))
        {
          my $type_id = $ptr_dwarf_h->{$act_k}{'DW_AT_type'};
          $type_id = $1 if ($type_id =~ /<0x(\w+)>/);
          $prt_types_h->{$act_k}{'type_id'} = $type_id;
          if(!exists($prt_types_h->{$type_id}))
          {
            $prt_types_h->{$type_id}{'count'}++;
            $prt_types_h->{'status'}='open';
            #print "$type_id ";
          }
        }
      }
      else
      {
        # no hash and no existing requested type => do nothing
      }
      # if it is a hash, enter the hash to parse inside calling again the function => recursive part
      if(ref($ptr_dwarf_h->{$act_k}) eq "HASH")
      {
        resolve_req_type(\%{$ptr_dwarf_h->{$act_k}},$prt_types_h);      
      }
    }
  }
} 

####################################################################
#
# get type that are required for fct interfaces from the %fct_info
#
####################################################################
sub get_req_type
{
  my %type_h_loc=();
  my $act_k = '';
  
  # foreach fct
  foreach $act_k (keys(%fct_info))
  {
    # if there are some input parameters
    if (exists($fct_info{$act_k}{'VARS'}))
    {
      # add all parameter type to the list of type to solve
      foreach (keys(%{$fct_info{$act_k}{'VARS'}}))
      {
        my $var_type = $fct_info{$act_k}{'VARS'}{$_};
        $var_type = $1 if ($var_type =~ /<0x(\w+)>/);
        $type_h_loc{$var_type}{'count'}++;
      } 
    }
    # add the function's returned type
    if (exists($fct_info{$act_k}{'DW_AT_type'}))
    {
        my $var_type = $fct_info{$act_k}{'DW_AT_type'};
        $var_type = $1 if ($var_type =~ /<0x(\w+)>/);
        $type_h_loc{$var_type}{'count'}++;
    }    
  }
  return(%type_h_loc);
}

####################################################################
#
# recursive fct to get the name and parameter of all functions contained in the elf file
#
####################################################################
sub get_fct_names
{
  my $ptr_h = $_[0];
  my %fct_info_loc=();
 
  foreach (keys(%{$ptr_h}))
  {
    my $act_k = $_;
    # parent shall not be parsed otherwise it goes back to upper level !
    if ($act_k ne 'parent')
    {
      # if it is a hash, enter the hash to parse inside calling again the function => recursive part
      if(ref($ptr_h->{$act_k}) eq "HASH")
      {
        %fct_info_loc = (%fct_info_loc,get_fct_names(\%{$ptr_h->{$act_k}}));      
      }
      # if the key is 'type', check if it is a subprg
      elsif ($act_k eq 'type')
      {
        # if it is a subprg, call the function to get all needed elements
        if ($ptr_h->{$act_k} eq "DW_TAG_subprogram")
        {
          %fct_info_loc = get_fct_info($ptr_h);             
        }
      }
      else
      {
        # no hash and no subprg => do nothing
      }
    }
  }
  return(%fct_info_loc );
} 

####################################################################
#
# sub function to get all information from on single C function
#
####################################################################
sub get_fct_info
{
  my $ptr_h = $_[0];
  my $fct_name = '';
  my %fct_info_loc = ();

  if (exists($ptr_h->{'DW_AT_name'}))
  {
    $fct_name = $ptr_h->{'DW_AT_name'};
    $fct_name =~ s/\(.*\)\s*:\s*//;
    if (exists($ptr_h->{'DW_AT_external'}))
    {
      $fct_info_loc{$fct_name}{'DW_AT_external'}=$ptr_h->{'DW_AT_external'};
    }
    if (exists($ptr_h->{'DW_AT_type'}))
    {
      $fct_info_loc{$fct_name}{'DW_AT_type'}=$ptr_h->{'DW_AT_type'};
    }
    if (exists($ptr_h->{'DW_AT_inline'}))
    {
      $fct_info_loc{$fct_name}{'DW_AT_inline'}=$ptr_h->{'DW_AT_inline'};
    }
    foreach my $act_k (%{$ptr_h})
    {
      if ((ref($ptr_h->{$act_k}) eq "HASH") && ($ptr_h->{$act_k}{'type'} eq 'DW_TAG_formal_parameter') )
      {
        # put into the fct_info_loc as key the name of the variable and as value the type
        # should check before if the keys exists !
        my $var_name = $ptr_h->{$act_k}{'DW_AT_name'};
        $var_name = $1 if ($var_name =~ /^.*:\s+(\w+)/);
        #print "no param name for function $fct_name\n" if ($var_name eq '');
        # if there is no var name, take the key number as var name
        # the non existence of a var name comes from the fact that it is a library
        if ($var_name eq '')
        {
          $var_name=$act_k;
        } 
        $fct_info_loc{$fct_name}{'VARS'}{$var_name}=$ptr_h->{$act_k}{'DW_AT_type'};
        $fct_info_loc{$fct_name}{'VARS_ORDER'}{$act_k}=$var_name;
      }
    }
    #$fct_info_loc{$fct_name}{'REF'}=$ptr_h;   # could be used to have a link between subprg list and full dwarf info
  }
  else
  {
    #print "  No fct name in function (inlined fct)  ";
    #print "Abstract origin from elf file: ".$ptr_h->{'DW_AT_abstract_origin'} if (exists($ptr_h->{'DW_AT_abstract_origin'}));
    #print "\n   Will not be listed\n";
  } 
  #print "fct name:".$fct_name.":\n";  
  #print Dumper \%fct_info_loc;
  return(%fct_info_loc);
}


####################################################################
#
# remove some unwanted functions
#
####################################################################
sub remove_fct()
{

foreach (keys(%fct_tab_h))
{
  # these functions must be removed otherwise Tasking is generating an "unknown error"
  # ABS comes from the parsing of the Hightec generated file that is not perfect.
  # also remove lot of functions from EB OS that begins with os_, otherwise the list is too big
  # and generate (I do not know why, TODO !) a modified HEX where the adresses in 0x80000000 is no more the same
  delete $fct_tab_h{$_} if ($_ =~ /^copysign$|^fputc$|^modf$|^modfl$|^sscanf$|^strlen$|^toupper$|^ungetc$|^vsprintf$|^_|^os_|^ABS$/i);
}

}

sub generate_output_file()
{
  my $function_str ='';
  
  # add the fct table
  $fct_c_table_str .= "\n};";
  $function_str = $fct_c_table_str;
  $param_in_str .= "\n\n\n";
  # add the extern prototype
  $param_in_str .= $fct_prototyp_str;
   
  open (FILE,"$gen_file_path") or die ("$!: \ncannot read $gen_file_path\n");
  {
  	local $/;
  	$header_str=<FILE>;
  }
  close(FILE);
  
  $header_str =~ s/DEMO_ANY_FCT_LIST_STR/$function_str/;
  $header_str =~ s/DEMO_ANY_FCT_IN_PAR_LIST_STR/$param_in_str/;
  
  #remove the t (template) at the end of the name
  $gen_file_path=~ s/t$//i;
  
  open (FILE,">${gen_file_path}") or die ("$!: \ncannot write to $gen_file_path\n");
  print FILE $header_str;
  close(FILE);
}

sub gen_op_file_Only_Demoapp()
{
  my $function_str ='';
  my $fct_structure ='';
  
  # add the fct table
  $function_str = $fct_c_table_str;
  $function_str .= "\n\n\n";
  # add the extern prototype
  $function_str .= $fct_prototyp_str;
   
  open (FILE,"$gen_file_path") or die ("$!: \ncannot read $gen_file_path\n");
  {
  	local $/;
  	$header_str=<FILE>;
  }
  close(FILE);
  
  $header_str =~ s/DEMO_ANY_FCT_LIST_STR//;

$fct_structure = "\nconst DemoApp_AnyFctListType DemoApp_AllFctList[]=";
$fct_structure .= "\n{";
$fct_structure .= "\n  {\"demoapp\",DemoApp,0,0,0}";
$fct_structure .= "\n};";
  
  $header_str =~ s/DEMO_ANY_FCT_IN_PAR_LIST_STR/$fct_structure/;
  
  #remove the t (template) at the end of the name
  $gen_file_path=~ s/t$//i;
  
  open (FILE,">${gen_file_path}") or die ("$!: \ncannot write to $gen_file_path\n");
  print FILE $header_str;
  close(FILE);
}