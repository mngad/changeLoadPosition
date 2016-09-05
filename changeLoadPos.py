#!/usr/bin/python3
import csv
import copy

f = open('loadPosition.csv') #opens initial loadPosition.csv
csv_f = csv.reader(f)
o = open('loadPositionEdit.csv','w') #opens new loadPosition.csv
csv_o = csv.writer(o)
for row in csv_f:
      changedRow = row.copy()
      for i in range(0,5):
          if i > 0:
              changedRow = row.copy() #Resets changedRow
              changedRow[0] = row[0]+str(i)
              if i == 1:
                  changedRow[2] = int(row[2])-1 #North
              if i == 2:
                  changedRow[1] = int(row[1])+1 #East
              if i == 3:
                  changedRow[2] = int(row[2])+1 #South
              if i == 4:
                  changedRow[1] = int(row[1])-1 #West
          csv_o.writerow(changedRow)
o.close()
o2 = open('loadPositionEdit.csv')
csv_o2 = csv.reader(o2)
for row in csv_o2:
      print(row)
