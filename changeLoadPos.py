import csv

f = open('loadPosition.csv')
csv_f = csv.reader(f)

o = open('loadPositionEdit.csv','w')
csv_o = csv.writer(o)
for row in csv_f:
      print row
      changedRow = row
      for i in range(0,5):
          for x in range(0,len(changedRow)):
              changedRow[x] = row[x]
              print changedRow[x]
          if i > 0:
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
print '----------------------------------'
o.close()
o2 = open('loadPositionEdit.csv')
csv_o2 = csv.reader(o2)
for row in csv_o2:
      print row
