import random
def greet(bot_name,birthyear):
    print("Hey! My name is ",bot_name ," and i was created in ",birthyear)
def remindName():
    print("Can u remind me your name: ")
    name=input()
    print("Ohh yes,I remember you ",name)
def guessAge(low,hi):
    randomINT=random.randrange(low,hi,1)
    print("I tried to guess your Age : ",randomINT)
def count(n):
    for i in range(1,n+1):
        print(i)
def checkProgrammingSkill():
    print("Which of the following is not a STL in C++ : ")
    print("1.Map")
    print("2.Set")
    print("3.Multiset")
    print("4.tuple")
    ans=int(input("give me an option"))
    if(ans!=4):
        print("You need to study,its correct and is tuple")
    else:
        print("Its great u know the answer.But U should always increase your knowledge")
def end():
    print('Congratulations, have a nice day!')
    print('.................................')
    print('.................................')
    print('.................................')

greet("Jarvis", 2022)
remindName()
print("Can U tell me two numbers and i guess your age")
low=int(input())
hi=int(input())
guessAge(low, hi)
print("I can count till any number .You can test me!!")
n=int(input("Give me a number"))
count(n)
checkProgrammingSkill()
end()

