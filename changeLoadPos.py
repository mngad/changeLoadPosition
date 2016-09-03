import csv

f = open('loadPosition.csv')
csv_f = csv.reader(f)

o = open('loadPositionEdit.csv','w')
csv_o = csv.writer(o)

for row in csv_f:
      print row
      for i in range(0,5):
          csv_o.writerow(row)
