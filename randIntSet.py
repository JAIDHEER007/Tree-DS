import requests
import os

cwd = os.path.dirname(__file__)

baseUrl = "https://www.random.org/integer-sets/?sets=1&num={count}&min={minLimit}&max={maxLimit}&order=index&format=plain&rnd=new"

# Format: [count, minLimit, maxLimit]
# Change it

# Limits
# count: [1, 10**4]
# minLimit = -10**9
# maxLimit = 10**9
dataSet = [
    [5, 1, 20],
    [10**4, -10**9, 10**9]
]

fileCount = 1
for data in dataSet:
    req = requests.get(url = baseUrl.format(count = data[0],
                                            minLimit = data[1], 
                                            maxLimit = data[2]))
    randData = req.text.strip()

    # Checking if the randData contains error
    try:
        if randData.find("Error") == -1:
            with open(os.path.join(cwd, "input{0}.txt".format(fileCount)), "w") as fileHandle:
                fileHandle.write(str(data[0])+"\n")
                fileHandle.write(randData)
            fileCount += 1
        else:
            raise Exception("found an Error with dataset {setNumber} \n{msg}".format(setNumber = (fileCount - 1), msg = randData))
    except Exception as exp:
        print(exp)
        fileCount -= 1