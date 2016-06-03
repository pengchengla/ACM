#!/usr/bin/python
fin = open("other.cpp","r")
fout = open("other2.cpp","w")
for line in fin:
    line = line.strip()[3:]
    fout.write(line + "\n")
fin.close()
fout.close()
