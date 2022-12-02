def addnumber():
    name=input("name:")
    if name not in book:
        book[name]=[]
        print("you can add 3 number. also to finish entering numbers, enter -1")
        for i in range(3):
            number=input("Number:")
            if number=="-1":
                break
            book[name].append(number)
    else:
        if len(book[name])<3:
            print("you can add",3-len(book[name]) ,"number.also to finish entering numbers, enter -1")
            for i in range(3-len(book[name])):
                number=input("number:")
                if number!="-1":
                    book[name].append(number)
                else:
                    break
        else:
            print("sorry you can't add number :)")
def removenumber():
    name=input("enter the name you want to delete:")
    if name in book:
        print(name,book[name])
        n=int(input("which number do you want to delete? 1 to first, 2 to second and 3 for third:"))
        book[name].pop(n-1)
        print("number removed successfully!")
    else:
        print(name, "was not found")
def search():
    name=input("enter name:")
    if name in book:
        print(name,"phonenumber(s): ",book[name])
    else:
        print("was not found")
def printphonebook():
    for i in book.keys():
        print(i,book[i])
book={}
while True:
    print('''1.add number
2.Remove number
3.Search
4.print phone book
5.exit :(''')
    n = int(input("choose what do you want from 1 to 5:"))
    print()
    if n==1:
        addnumber()
    elif n==2:
        removenumber()
    elif n==3:
        search()
    elif n==4:
        printphonebook()
    elif n==5:
        print("bye!")
        break
    else:
        print("I told you choose from 1 to 5 :(")
    print()