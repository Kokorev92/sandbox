import csv

FILENAME = "exam_results.csv"

def get_key(man):
    return man[1]

results = []
with open(FILENAME, "r", newline="") as file:
    reader = csv.reader(file)
    for row in reader:
        man = list()
        man.append(row[0])
        man.append(row[4])
        results.append(man)

print(results)

sort_result = sorted(results, key=get_key)
print(sort_result)