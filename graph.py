import matplotlib.pyplot as plt
import csv
import sys

x = []
y = []
total = 0
my_label = ""
header_read = False
filename = "results.txt"

if len(sys.argv) == 2:
    filename = sys.argv[1]

path = filename

with open(path, 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        if not header_read:
            my_label=row[3]
            header_read=True
        else:
            x.append(float(row[0]))
            y.append(float(row[1]))
            total += float(row[1])

print("Total sorting time: ", total/1000.0, "s")
plt.scatter(x,y, label=my_label)

plt.xlabel('Nr sortowanej tablicy')
plt.ylabel('Czas sortowania [ms]')
plt.legend()
plt.show()
