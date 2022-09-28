import random
max_num=10000000
with open("data.txt","wb") as datafile:
    datafile.write(str(max_num)+'\n')
    for i in range(max_num):
        datafile.write(str(random.randint(0,max_num))+' ')