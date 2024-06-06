#Lecture 2 - Notes
x = seq(1, 10, 2)
x[-c(1,5)] #Deletes first and last elements
x

x = 1:3
y = 4:6
M1 = rbind(x,y)
M1
M1[,1] #Gets all rows, 1st column
M2 = cbind(x,y)
M2[,2] #Always displays as a horizontal vector

M2[x] #Binding names can be used as indices
M2[y]
M2[x] + M2[y] #Component addition
M1 %*% M2 #Dot product/matrix multiplication

cof_A = matrix(c(2,1,5,-3,2,1,-1,2,-1),nrow=3) #c for concatenation
cof_A
con = matrix(c(2,15,4),nrow=3)
con
solve(cof_A,con)

#Coercion
x = c("first", 2.3) #Implicit type conversion to common type
x
typeof(x)
y = c(7,F)
y
typeof(y)

z = c(1, "Canada", 3)
z
typeof(z)

xnum = as.numeric(x)
xnum

xchar = as.character(x)
xchar

x = c(-2,3,1.2)
as.integer(x) #Truncates to whole number

x = c(T,F,T,T,T,F)
as.numeric(x)

#Lists
xlist = list(17,17L,17.0,c('hello',22,F),c(7,"Temp"),2-3i)
str(xlist)

xlist[1]
xlist[2]
xlist[3]
xlist[4]
xlist[5]
xlist[6]

xlist[[1]]
xlist[[2]]
xlist[[3]]
xlist[[4]]
xlist[[5]]
xlist[[6]]

#NA-not available, NaN-not a number, Inf-infinity
x = as.numeric(1/10)
is.finite(x)
is.infinite(x)

x = 0/0 #NaN
x
x = 1/0 #Inf
x

x = sqrt(-1) #NaN
x

x = c(2,NA,3.3,4,NA,NA,6)
is.na(x)

#Create dataframe
x = runif(4) #uniform distribution (n=4) generates n random numbers
x

x = floor(1000*x)
x

df = data.frame(ID=x, Name=c("David", "Sara", "Chandler", "Alex"))
df
nrow(df) #gives number of rows
ncol(df) #gives number of columns

#Variables - Qualitative vs Quantitative
#Measurements are considered to be a continuous variable
install.packages("iriR")
library(dslabs)
?dslabs
?iris
View(iris)