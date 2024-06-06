#Comments are delimited by '#'

#Built-in Functions
x <- 1:4
x
y <- c(1, 2, 3, 4, NA) #NA=Not Available
y

mean(x)
sd(x)
var(x)
mean(y)

mean(y, na.rm = TRUE) #removes na values

#Getting Help; Commenting, Notifications
?sd
?library

y <- x^2
y

#Basic Types of Objects (Atomic Objects)
#character
#integer
#real
#logical - boolean

x1 <- "This is a character string"
typeof(x1)

x2 <- 26L
typeof(x2)

x3 <- 26
typeof(x3)

#uppercase T/F are valid booleans

#Vector - An array-like objects with a finite ordered sequence of atomic objects of the same type
x <- c(2,3,-5,7,-2)
x
typeof(x)
x[4]
x[1:3] #subvector, 1-indexed

x[c(1,3)] #yields new
x[-3] #hides the index specified
x

x>0
table(x>0)

3 %in% x #infix

#vectors can be added and multiplied with the same dimensions

x1 <- seq(from=1, to=7, by=1) #specify range and step
length(x1)
x1

Paul = "Stuck inside these 4 walls, sent inside forever"
rm(Paul)


x = c(2,3,-5,7,2)
x1 = seq(from=1, to=7, by=1)
x2 = seq(from=2, to=109, by=2)
x3 = c(2.3, -1.)
x4 = c(T,F)
x5 = c(TRUE, FALSE)
x6 = c("me", "you", "everybody")
str(x6) #structure of list
nchar(x6) #element character counter

x = 1:3
y = 4:6
M1 = rbind(x,y) #adds rowwise
M2 = cbind(x,y) #adds columnwise

str(M1)
str(M2)

M1[,1] #(r,c)

M1[1,1]
