a = int(input())

for i in range(a):
    date1, date2 = input().split()
    flg = 0
    workMonth, workDay, workYear = map(int, date1.split("/"))
    dueMonth, dueDay = map(int, date2.split("/"))
    if dueMonth != workMonth:
        ans = str(date2) + "/" + str(workYear)
        if abs(dueMonth - workMonth) == 1:
            if dueMonth > workMonth:
                if dueMonth == 1 or dueMonth == 3 or dueMonth == 5 or dueMonth == 7 or dueMonth == 8 or dueMonth == 10 or dueMonth == 12:
                    if 31-workDay + dueDay <= 7:
                        if 31-workDay + dueDay == 1:
                            print(ans, "IS", 31 - workDay + dueDay, "DAY AFTER")
                        else:
                            print(ans, "IS", 31 - workDay + dueDay, "DAYS AFTER")
                    else:
                        print("OUT OF RANGE")
                elif dueMonth == 2:
                    if workYear%4 == 0:
                        if workYear%100 == 0 and workYear != 2000:
                            if 28-workDay + dueDay <= 7:
                                if 28-workDay + dueDay == 1:
                                    print(ans, "IS", 28 - workDay + dueDay, "DAY AFTER")
                                else:
                                    print(ans, "IS", 28 - workDay + dueDay, "DAYS AFTER")
                            else:
                                print("OUT OF RANGE")
                        else:
                            if 29-workDay + dueDay <= 7:
                                if 29-workDay + dueDay == 1:
                                    print(ans, "IS", 29 - workDay + dueDay, "DAY AFTER")
                                else:
                                    print(ans, "IS", 29 - workDay + dueDay, "DAYS AFTER")
                            else:
                                print("OUT OF RANGE")
                    else:
                        if 28-workDay + dueDay <= 7:
                            if 30-workDay + dueDay == 1:
                                print(ans, "IS", 28 - workDay + dueDay, "DAY AFTER")
                            else:
                                print(ans, "IS", 28 - workDay + dueDay, "DAYS AFTER")
                        else:
                            print("OUT OF RANGE")
                else:
                    if 31-workDay + dueDay <= 7:
                        if 31-workDay + dueDay == 1:
                            print(ans, "IS", 31 - workDay + dueDay, "DAY AFTER")
                        else:
                            print(ans, "IS", 31 - workDay + dueDay, "DAYS AFTER")
                    else:
                        print("OUT OF RANGE")
            else:
                if dueMonth == 1 or dueMonth == 3 or dueMonth == 5 or dueMonth == 7 or dueMonth == 8 or dueMonth == 10 or dueMonth == 12:
                    if 30-dueDay+workDay<= 7:
                        if 30-dueDay+workDay == 1:
                            print(ans, "IS", 30-dueDay+workDay, "DAY AFTER")
                        else:
                            print(ans, "IS", 30-dueDay+workDay, "DAYS AFTER")
                    else:
                        print("OUT OF RANGE")
                elif dueMonth == 2:
                    if workYear%4 == 0:
                        if workYear%100 == 0 and workYear != 2000:
                            if 28-dueDay+workDay <= 7:
                                if 28-dueDay+workDay == 1:
                                    print(ans, "IS", 28-dueDay+workDay, "DAY AFTER")
                                else:
                                    print(ans, "IS", 28-dueDay+workDay, "DAYS AFTER")
                            else:
                                print("OUT OF RANGE")
                        else:
                            if 29-dueDay+workDay<= 7:
                                if 29-dueDay+workDay == 1:
                                    print(ans, "IS", 29-dueDay+workDay, "DAY AFTER")
                                else:
                                    print(ans, "IS", 29-dueDay+workDay, "DAYS AFTER")
                            else:
                                print("OUT OF RANGE")
                    else:
                        if 28-dueDay+workDay <= 7:
                            if 30-workDay + dueDay == 1:
                                print(ans, "IS", 28 -dueDay+workDay, "DAY AFTER")
                            else:
                                print(ans, "IS", 28 -dueDay+workDay, "DAYS AFTER")
                        else:
                            print("OUT OF RANGE")
                else:
                    if 31-dueDay+workDay <= 7:
                        if 31-dueDay+workDay == 1:
                            print(ans, "IS", 31 -dueDay+workDay, "DAY AFTER")
                        else:
                            print(ans, "IS", 31 -dueDay+workDay, "DAYS AFTER")
                    else:
                        print("OUT OF RANGE")
        elif abs(dueMonth - workMonth) == 11:
            if dueMonth < workMonth:
                ans = str(date2) + "/" + str(workYear+1)
                if 31-workDay + dueDay <= 7:
                    if 31-workDay + dueDay == 1:
                        print(ans, "IS", 31 - workDay + dueDay, "DAY AFTER")
                    else:
                        print(ans, "IS", 31 - workDay + dueDay, "DAYS AFTER")
                else:
                    print("OUT OF RANGE")
            else:
                ans = str(date2) + "/" + str(workYear-1)
                if 31-dueDay + workDay <= 7:
                    if 31-dueDay + workDay == 1:
                        print(ans, "IS", 31-dueDay + workDay, "DAY PRIOR")
                    else:
                        print(ans, "IS", 31-dueDay + workDay, "DAYS PRIOR")
                else:
                    print("OUT OF RANGE")
        else:
            print("OUT OF RANGE")
                    
    else:
        ans = str(date2) + "/" + str(workYear)
        if abs(dueDay - workDay) <=7 and dueDay - workDay != 0:
            if dueDay > workDay:
                if dueDay-workDay == 1:
                    print(ans, "IS", dueDay-workDay, "DAY AFTER")
                else:
                    print(ans, "IS", dueDay-workDay, "DAYS AFTER")
            else:
                if dueDay-workDay == 1:
                    print(ans, "IS", workDay-dueDay, "DAY PRIOR")
                else:
                    print(ans, "IS", workDay-dueDay, "DAYS PRIOR")
        elif dueDay - workDay == 0:
            print("SAME DAY")
        else:
            print("OUT OF RANGE")