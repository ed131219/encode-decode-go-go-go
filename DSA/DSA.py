
# coding: utf-8

# In[ ]:


from random import randint,randrange
import hashlib
import random
import sys

def generateNum(num):                            #generate num of bits number
    output = ""
    for i in range(num):
        if i ==0 or i == num-1:
            output += '1'
        else:
            temp = randint(0,9)
            output += str(temp % 2)
    return int(output,2)

def miller_rabin_test(n):                        #check if number is prime
    test = n
    lowPrimes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,109, 
                 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
                 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
                 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661,
                 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827,
                 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991,
                 997]
    for i in lowPrimes:
        if (test % i == 0):
            return False
    r = 0
    s = n -1
    while s % 2 == 0:
        s = s // 2
        r += 1
    for round in range(20):
        tmp = random.randrange(2, (n-1))   #random number between 2 ~ (n-1)
        v = pow(tmp, s, n)                 # v = tmp^s mod n
        if v != 1 and v != (n-1):           # v !=1 means not pass yet
            for i in range(r):
                if i == (r-1):
                    return False
                else:
                    v = (v**2) % n
                if v == 1:
                    return False
                elif v == (n-1):
                    break
    return True

def findPrime():                                   #找質數 p、q, q 為 160 bits, p 為 1024 bits, 先找出 q, 再去找 p，會比較好找
    flag = False
    p = 0
    q = 0
    n = 0
    if len(bin(p)) != 1026:
        while (miller_rabin_test(p)) == False:
            while (miller_rabin_test(q)) == False:
                q = generateNum(160)
                n = q
            for i in range(864):
                q = q * 2
            p = q + 1
    return p, n

def findalpha(p, q):                                #利用 p、q 找 alpha
    alpha = 1
    h = 2
    while alpha == 1:
        alpha = pow(h, int((p-1)/q), p)
        h += 1
    return alpha

def findPrivateKey(p, q, alpha):                    #在 0 ~ q 之間隨機找一個數當 private key (d),同時利用 alpha、d、p 找 beta
    pri = randint(0,q)
    beta = pow(alpha, pri, p)
    return pri, beta

def signature(p, q, alpha, beta, d, message):       #簽章 : 先把 message 做 hash，在 0 ~ q 之間隨機找出 k，利用 alpha、k、p 得到 r
    r = 0                                           #再利用 hash 後的 message、d、r、inverse k、q 得到 s
    s = 0
    sh = hashlib.sha1()
    sh.update(message.encode())
    hexMessage = sh.hexdigest()
    intMessage = int(hexMessage,16)
    while len(bin(r)) != 162 or len(bin(int(s))) != 162:
        k = randint(0,q)
        r = pow(alpha,k,p) % q
        invk = pow(k,q-2,q)
        s = (intMessage + d * r) * invk % q
    return r,s,intMessage

def verify(p, q, alpha, beta, intMessage, r, s):    #驗證: 先找到 inverse s，再利用 inverse s 和 q 得到 W，利用 w、hash 後的 message、q 得到u1
    invs = pow(int(s),q-2,q)                        #利用 w、r、q 得到 u2
    w = invs % q                                    #最後利用 alpha、u1、beta、u2、p、q 得到 v
    u1 = w * intMessage % q                         #若 v = (r mod q) 則驗證成功
    u2 = w * r % q
    v =  (pow(alpha,u1,p) * pow(beta,u2,p)) % p % q
    print(" v =   ", v, "\n")
    print(" r%q = ", r%q, "\n")
    if v == (r%q):
        print(" v = (r%q): Verify Yes!")
    else:
        print(" v != (r%q): Verify No!")

def main():
    print("----------------------- Generate key -----------------------\n")
    p,q = findPrime()                       
    alpha = findalpha(p, q)
    d, beta = findPrivateKey(p,q,alpha)
    print(" p = ", p, "\n")
    print(" q = ", q, "\n")
    print(" alpha = ", alpha, "\n")
    print(" beta = ", beta, "\n")
    print(" private key = ", d, "\n")
    #print("Message = myDSAbooo")
    
    print("\n----------------------- Signature ------------------------\n")
    
    message = input(" message = ")
    print("\n")
    r,s, hashMessage = signature(p, q, alpha, beta, d, message)
    print(" r = ", r, "\n")
    print(" s = ", s, "\n")
    print(" hash message = ", hashMessage, "\n")
    
    print("\n------------------------- Verify -------------------------\n")
    verify(p, q, alpha, beta, hashMessage, r, s)

if "__main__":
    main()