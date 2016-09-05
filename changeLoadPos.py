#!/usr/bin/python3
import csv
import copy

f = open('loadPosition.csv')
csv_f = csv.reader(f)
changedRow = [0,0,0,0]
o = open('loadPositionEdit.csv','w')
csv_o = csv.writer(o)
for row in csv_f:
      changedRow = [0,0,0,0]
      #print(row)
      changedRow = row.copy()
      for i in range(0,5):
          if i > 0:
              #print('row = ' + str(row))

              changedRow = row.copy()

              changedRow[0] = row[0]+str(i)
              if i == 1:
                  changedRow[2] = int(row[2])-1
              if i == 2:
                  changedRow[1] = int(row[1])+1
              if i == 3:
                  changedRow[2] = int(row[2])+1
              if i == 4:
                  changedRow[1] = int(row[1])-1
          csv_o.writerow(changedRow)
print('----------------------------------')
o.close()
o2 = open('loadPositionEdit.csv')
csv_o2 = csv.reader(o2)
for row in csv_o2:
      print(row)
