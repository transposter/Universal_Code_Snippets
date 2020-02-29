/*This C++ program encodes any message using RSA Algorithm. Input is case sensitive and works only for all characters. RSA is one of the first practicable public-key cryptosystems and is widely used for secure data transmission. In such a cryptosystem, the encryption key is public and differs from the decryption key which is kept secret. In RSA, this asymmetry is based on the practical difficulty of factoring the product of two large prime numbers, the factoring problem. RSA stands for Ron Rivest, Adi Shamir and Leonard Adleman.*/

/*
 * C++ Program to Implement the RSA Algorithm
 */
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
        {
            if (pr % i == 0)
                return 0;
        }
    return 1;
}
int main()
{
    cout << "\nENTER FIRST PRIME NUMBER\n";
    cin >> p;
    flag = prime(p);
    if (flag == 0)
        {
            cout << "\nWRONG INPUT\n";
            exit(1);
        }
    cout << "\nENTER ANOTHER PRIME NUMBER\n";
    cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q)
        {
            cout << "\nWRONG INPUT\n";
            exit(1);
        }
    cout << "\nENTER MESSAGE\n";
    fflush(stdin);
    cin >> msg;
    for (i = 0; msg[i] != NULL; i++)
        m[i] = msg[i];
    n = p * q;
    t = (p - 1) * (q - 1);
    ce();
    cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << e[i] << "\t" << d[i] << "\n";
    encrypt();
    decrypt();
    return 0;
}
void ce()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
        {
            if (t % i == 0)
                continue;
            flag = prime(i);
            if (flag == 1 && i != p && i != q)
                {
                    e[k] = i;
                    flag = cd(e[k]);
                    if (flag > 0)
                        {
                            d[k] = flag;
                            k++;
                        }
                    if (k == 99)
                        break;
                }
        }
}
long int cd(long int x)
{
    long int k = 1;
    while (1)
        {
            k = k + t;
            if (k % x == 0)
                return (k / x);
        }
}
void encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
        {
            pt = m[i];
            pt = pt - 96;
            k = 1;
            for (j = 0; j < key; j++)
                {
                    k = k * pt;
                    k = k % n;
                }
            temp[i] = k;
            ct = k + 96;
            en[i] = ct;
            i++;
        }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}
void decrypt()
{
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
        {
            ct = temp[i];
            k = 1;
            for (j = 0; j < key; j++)
                {
                    k = k * ct;
                    k = k % n;
                }
            pt = k + 96;
            m[i] = pt;
            i++;
        }
    m[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);
}

/*

ENTER FIRST PRIME NUMBER
47

ENTER ANOTHER PRIME NUMBER
53

ENTER MESSAGE
Dharmendra

POSSIBLE VALUES OF e AND d ARE
3	1595
5	957
7	1367
11	435
17	985
19	1259
29	165
31	463
37	1293
41	2217
43	1947
59	1419
61	549
67	2035
71	1415
73	1409
79	1847
83	2075
89	2177
97	1233
101	1421
103	2183

THE ENCRYPTED MESSAGE IS
x`a???]??a
THE DECRYPTED MESSAGE IS
Dharmendra