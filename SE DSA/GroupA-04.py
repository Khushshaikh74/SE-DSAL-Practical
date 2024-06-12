set1 = set()
set2 = set()

while (True):
 print("\n-----------DSAL PRACTICAL NO :- 02(A-4)----------")
 print("\n**SET OPERATION")
 print("1:Insert")
 print("2:Size")
 print("3:Remove")
 print("4:Search ")
 print("5:Union ")
 print("6:Intersection")
 print("7:Subset ")
 print("8:Difference")
 print("9:Exit")
 choice = int(input("\nEnter your Choice : "))
 if (choice == 1):
     n1 = int(input("\nEnter the number of elements in set1: "))
     for i in range(n1):
         data_name = input("Enter the elements in set1: ")
         # insert
         set1.add(data_name)
 
     n2 = int(input("\nEnter the number of elements in set2: "))
     for i in range(n2):
         data_name = input("Enter the elements in set2: ")
         # insert
         set2.add(data_name)
         print("\nSet1 :", set1, '\nSet2 :', set2)
 
 elif (choice == 2):
     print("Size of set1: ", len(set1))
     print("Size of set2: ", len(set2))

 elif (choice == 3):
     print('\nRemove element from set1 and set2 (1 for set1 & 2 for set2)')
     inp = int(input())
     if inp == 1:
         set1.pop()
         print(set1)
     if inp == 2:
         set2.pop()
         print(set2)
 
 elif (choice == 4):
     ip = input("\nEnter element you want to search: ")
     if ip in set1:
         print("set1 contains the element ", ip)
     if ip in set2:
         print("set2 contains the element ", ip)
 
 elif (choice == 5):
     print("Union is :", set1.union(set2))

 elif (choice == 6):
     print("Intersection is : ", set1.intersection(set2))

 elif (choice == 7):
     print("Subset is :", set1.issubset(set2))

 elif (choice == 8):
     differ = set2.difference(set1)
     print("Difference is : ",differ)

 elif (choice == 9):
     print("----------------SUCCESSFULLY TERMINATED----------------")
     break

 else:
     print("Invalid Choice")