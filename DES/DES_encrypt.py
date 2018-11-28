
# coding: utf-8

# In[1]:


import sys

IP = [
58 , 50 , 42 , 34 , 26 , 18 , 10 ,  2 ,
60 , 52 , 44 , 36 , 28 , 20 , 12 ,  4 ,
62 , 54 , 46 , 38 , 30 , 22 , 14 ,  6 ,
64 , 56 , 48 , 40 , 32 , 24 , 16 ,  8 ,
57 , 49 , 41 , 33 , 25 , 17 ,  9 ,  1 ,
59 , 51 , 43 , 35 , 27 , 19 , 11 ,  3 ,
61 , 53 , 45 , 37 , 29 , 21 , 13 ,  5 ,
63 , 55 , 47 , 39 , 31 , 23 , 15 ,  7 ]

IP_1 = [
40 ,  8 , 48 , 16 , 56 , 24 , 64 , 32 ,
39 ,  7 , 47 , 15 , 55 , 23 , 63 , 31 ,
38 ,  6 , 46 , 14 , 54 , 22 , 62 , 30 ,
37 ,  5 , 45 , 13 , 53 , 21 , 61 , 29 ,
36 ,  4 , 44 , 12 , 52 , 20 , 60 , 28 ,
35 ,  3 , 43 , 11 , 51 , 19 , 59 , 27 ,
34 ,  2 , 42 , 10 , 50 , 18 , 58 , 26 ,
33 ,  1 , 41 ,  9 , 49 , 17 , 57 , 25 ]

PC_1 = [
57 , 49 , 41 , 33 , 25 , 17 ,  9 ,  1 ,
58 , 50 , 42 , 34 , 26 , 18 , 10 ,  2 ,
59 , 51 , 43 , 35 , 27 , 19 , 11 ,  3 ,
60 , 52 , 44 , 36 , 63 , 55 , 47 , 39 ,
31 , 23 , 15 ,  7 , 62 , 54 , 46 , 38 ,
30 , 22 , 14 ,  6 , 61 , 53 , 45 , 37 ,
29 , 21 , 13 ,  5 , 28 , 20 , 12 ,  4 ]

PC_2 = [
14 , 17 , 11 , 24 ,  1 ,  5 ,  3 , 28 ,
15 ,  6 , 21 , 10 , 23 , 19 , 12 ,  4 ,
26 ,  8 , 16 ,  7 , 27 , 20 , 13 ,  2 ,
41 , 52 , 31 , 37 , 47 , 55 , 30 , 40 ,
51 , 45 , 33 , 48 , 44 , 49 , 39 , 56 ,
34 , 53 , 46 , 42 , 50 , 36 , 29 , 32 ]

E = [
32 ,  1 ,  2 ,  3 ,  4 ,  5 ,  4 ,  5 ,
6 ,  7 ,  8 ,  9 ,  8 ,  9 , 10 , 11 ,
12 , 13 , 12 , 13 , 14 , 15 , 16 , 17 ,
16 , 17 , 18 , 19 , 20 , 21 , 20 , 21 ,
22 , 23 , 24 , 25 , 24 , 25 , 26 , 27 ,
28 , 29 , 28 , 29 , 30 , 31 , 32 ,  1 ]

P = [
16 ,  7 , 20 , 21 , 29 , 12 , 28 , 17 ,
1 , 15 , 23 , 26 ,  5 , 18 , 31 , 10 ,
2 ,  8 , 24 , 14 , 32 , 27 ,  3 ,  9 ,
19 , 13 , 30 ,  6 , 22 , 11 ,  4 , 25 ]

S1 = [
[14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
[0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
[4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
[15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13]]

S2 = [
[15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10],
[3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5],
[0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15],
[13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9]]

S3 = [
[10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8],
[13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1],
[13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7],
[1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12]]

S4 = [
[7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15],
[13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9],
[10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4],
[3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14]]

S5 = [
[2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9],
[14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6],
[4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14],
[11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3]]

S6 = [
[12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11],
[10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8],
[9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6],
[4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13]]

S7 = [
[4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1],
[13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6],
[1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2],
[6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12]]

S8 = [
[13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7],
[1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2],
[7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8],
[2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11]]

seq = [S1,S2,S3,S4,S5,S6,S7,S8]


# In[52]:


def Xor(a, b):
    c = ''
    for x,y in zip(a,b):
        c += str(ord(x) ^ ord(y))
    return c
class des :
    def __init__(self, plaintext, key):
        self.plaintext = plaintext
        self.key = key
        self.round = 1
        self.roundkey = ''    
        self.cipher = ''
        self.L = ''
        self.R = ''
#----------------------左位移round位------------------------
    def LShift(self, s):
        x = 2 
        if(self.round == 1 or self.round == 2 or self.round == 9 or self.round == 16):
            x = 1
        move = s[:x]
        residue = s[x:]
        return ''.join([residue, move])
#--------------------PC1後的KEY 56bit-----------------------
    def PC_key(self):
        pckey = ''
        for i in PC_1:
            pckey += self.key[i - 1]
        return pckey
#--------------------PCKEY 做transform----------------------
    def Transform(self, key_56):
        keyL = self.LShift(key_56[:28])
        keyR = self.LShift(key_56[28:])
        rkey = keyL + keyR
        print(len(rkey),'--',rkey)
        roundkey = ''
        for i in PC_2:
            roundkey +=  rkey[i - 1]
        self.roundkey = roundkey
        #print(len(roundkey),'++++',roundkey)
        self.key = rkey
        
#-----------------------------------------------------------
    def Initial_Permutation(self):
        for i in IP:
            self.cipher += self.plaintext[i - 1]
        
#-----------------------------------------------------------
#-----------------------------------------------------------
    def Expansion(self, cipherR):
        expanr = ''
        for i in E:
            expanr += cipherR[i - 1]
        return expanr
#-----------------------------------------------------------
    def S_box(self, cipherR):
        r = ''
        for i,j in enumerate(seq):
            x = ''
            y = ''
            z = ''
            x += cipherR[i * 6] + cipherR[i * 6 + 5]
            y += cipherR[i * 6 + 1] +  cipherR[i * 6 + 2] +  cipherR[i * 6 + 3] +  cipherR[i * 6 + 4]
            z = j[int(x,2)][int(y,2)]
            z = bin(z)
            z = z[2:]
            r += z.zfill(4)
        return r  
#-----------------------------------------------------------
    def Permutation(self, cipherR):
        x = ''
        for i in P:
            x += cipherR[i - 1]
        return x
#-----------------------------------------------------------
    def F_function(self, cipherR):
        #print(len(self.roundkey),'+++',self.roundkey)
        roundtext = Xor(self.Expansion(cipherR),self.roundkey)
        roundtext = self.S_box(roundtext)
        roundtext = self.Permutation(roundtext)
        return roundtext
#-----------------------------------------------------------
    def Round(self):
        cipherL = self.cipher[:32]
        cipherR = self.cipher[32:]
        excipherR = self.F_function(cipherR)
        self.L = cipherR
        self.R = Xor(cipherL,excipherR)
        self.cipher = self.L + self.R
#-----------------------------------------------------------
    def DES(self):
        #self.Transform(self.PC_key())
        self.key = self.PC_key()
        self.Initial_Permutation()
        for i in range(0,16):
            self.Transform(self.key) 
            self.Round()
            self.round += 1
        self.cipher = self.R + self.L
        cipher = ''
        for i in IP_1:
             cipher += self.cipher[i - 1]
        self.cipher = cipher
def main():
    ptext = input("Enter plaintext: ")
    bittext = bin(int(ptext, 16))
    bittext = bittext[2:]
    bittext = bittext.zfill(64)
    key = input("Enter key: ")
    key = bin(int(key, 16))
    key = key[2:]
    key = key.zfill(64)
    a = des(bittext, key)
    a.DES()
    print("Final -------------- ", hex(int(a.cipher,2)))


# In[54]:



if __name__ =="__main__":
    main()

