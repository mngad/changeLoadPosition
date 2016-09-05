#!/usr/bin/python3
import csv
import copy
import os
from shutil import copyfile

f = open('loadPosition.csv') #opens initial loadPosition.csv
csv_f = csv.reader(f)
o = open('loadPositionEdit.csv','w') #opens new loadPosition.csv
csv_o = csv.writer(o)
for row in csv_f:
      changedRow = copy.copy(row)
      for i in range(0,9):
          if i > 0:
              changedRow = copy.copy(row) #Resets changedRow
              changedRow[0] = row[0]+str(i)
              copyfile(str(row[0])+'.inp',str(changedRow[0])+'.inp')
              if i == 1:
                  changedRow[2] = int(row[2])-1 #North
              if i == 2:
                  changedRow[1] = int(row[1])+1 #East
              if i == 3:
                  changedRow[2] = int(row[2])+1 #South
              if i == 4:
                  changedRow[1] = int(row[1])-1 #West
              if i == 5:
                  changedRow[2] = int(row[2])-2 #North
              if i == 6:
                  changedRow[1] = int(row[1])+2 #East
              if i == 7:
                  changedRow[2] = int(row[2])+2 #South
              if i == 8:
                  changedRow[1] = int(row[1])-2 #West
          csv_o.writerow(changedRow)
o.close()
o2 = open('loadPositionEdit.csv')
csv_o2 = csv.reader(o2)
for row in csv_o2:
      print(row)
