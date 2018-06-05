__all__ = ["licensetime_check"]
from PyQt5 import QtCore


def licensetime_check(handler, userpath):
    import datetime
    defaultdaydate = datetime.datetime(2018, 1, 23, 00, 00)
    setdate = datetime.datetime(2018, 5, 5, 00, 00)
    todaydate = datetime.datetime.today()
    readate = handler.value('DATE' + '/install')
    if readate is None:
        if todaydate > setdate:
            print("notvalid")
            license = False
        else:
            print("valid")
            license = True
            timeinstall(userpath, setdate)
        if todaydate < defaultdaydate:
            print("notvalid")
            license = False
    else:
        # todaydate = datetime.datetime(2018, 5, 5, 00, 00)
        # expiredate = datetime.timedelta(days=3)
        if todaydate > readate:
            print("notvalid")
            license = False
        else:
            print("valid")
            license = True
        if todaydate < defaultdaydate:
            print("Don`t cheat")
            license = False
    return license


def timeinstall(hd_name, value):
    settings = QtCore.QSettings(
        hd_name, QtCore.QSettings.IniFormat)
    settings.setValue('DATE' + '/install', value)
    return
