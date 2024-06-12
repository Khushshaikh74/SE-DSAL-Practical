# Consider telephone book database of N clients. Make use of a hash table implementation
# to quickly look up client‘s telephone number. Make use of two collision handling
# techniques and compare them using number of comparisons required to find a set of
# telephone numbers

def tele_database():
    phone_data = []
    n = int(input("Enter Number of Clients :- "))
    print("Enter Phone Numbers --\n")
    for _ in range(n):
        x = int(input("--> "))
        phone_data.append(x)

    return phone_data


def hash_function_1(key_ele, m_size):
    h1 = key_ele % m_size
    return h1


def hash_function_2(key_ele):
    h2 = 1 + (key_ele % 11)
    return h2
    
def hash_3(key_ele, m_size):
    h_3 = key_ele % m_size
    return h_3


def hashtable(ht):
    print(f"\nHash Value \tKey")
    for ele in range(len(ht)):
        if ht[ele] != -1:
            print(f"\n\t{ele} \t---> \t{ht[ele]}")
        else:
            print(f"\n\t{ele}")

while(1):
    phone_database = tele_database()
    m = int(input("Enter Hash Table Size :- "))
    hash_table = [-1] * m

    print("\n......MENU.....\nIf collision occurs which collision resolution technique do you want to use?\n\t1. Linear probing\n\t2. Double Hashing\n\t3. Quadratic probing\n\t4. Exit")
    
    opt = int(input("Enter your choice: "))
    for k in phone_database:
        h_1 = hash_function_1(k, m)
        h_2 = hash_function_2(k)
        h_3 = hash_3(k, m)

        if hash_table[h_1] == -1:
            hash_table[h_1] = k
        else:
            if opt == 1:
                while hash_table[h_1] != -1:
                    h_1 = (h_1 + 1) % m  # Ensure the new index remains within bounds
                hash_table[h_1] = k
                
            elif opt == 2:
                i = 0
                while hash_table[h_1] != -1:
                    i += 1
                    h_1 = (h_1 + i * h_2) % m  # Ensure the new index remains within bounds
                hash_table[h_1] = k
                
            elif opt == 3:
                i = 0
                while hash_table[h_1] != -1:
                    i += 1
                    h_1 = (h_1 + i*i) % m  # Ensure the new index remains within bounds
                hash_table[h_1] = k    
        
                    
    hashtable(hash_table)
    print("*\n")
    
    if opt==4:
        print("Program Terminated Successfully...")
        break