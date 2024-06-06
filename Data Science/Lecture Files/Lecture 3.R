#Data frames
install.packages("dslabs")
library(dslabs)
data("murders")
?murders
View(murders)
class(murders) #View class type
str(murders) #View structure
head(murders)
tail(murders)

#Accessor - $
murders$population #Specify column within murders
names(murders) #Names of columns
pop = murders$population
length(pop)
class(pop)


#Factors
class(murders$region)
levels(murders$region)

#Sort
data("murders")
sort(murders$total) #sorts by increasing order
max(murders$total)
i_max = which.max(murders$total) #Get index of max
i_max
murders$state[i_max]
murders$state[which.min(murders$total)]

#New data set
install.packages("iriR")
library(iriR)
View(iris)

head(iris)
tail(iris)
nrow(iris)
ncol(iris)
dim(iris) #Get dimension

spec = iris$Species
spec

str(spec)
length(spec)

table(spec) #Count occurrences
head(iris[,1:3])
head(iris[, 'Petal.Length'])
iris[iris$Species=="versicolor",] #Subsets to all versicolor entries

iris[(iris$Species=="versicolor") & (iris$Sepal.Length <= 5.0), ]

x = iris$Petal.Length
y = iris$Sepal.Length

plot(x,y,pch=16,col=iris$Species) #pch gives point style, col

plot(x,y,pch=16,xlab="Petal Length", ylab="Sepal Length", main="Sepal Length vs Petal Length", col=iris$Species)

legend("topleft", legend=unique(iris$Species), fill=unique(iris$Species),bty="n") #bty is boundary

#Control Structures
#if else
x = 3
y = 4
if(x < y)
{
  y = 20
}
print(y)

y = -3
if(y > 0)
{
  cat(sprintf("%d is a positive number.\n", y))
}else if(y < 0)
{
  cat(sprintf("%d is a negative number.\n", y))
}


#For loop
for(i in 1:6)
{
  print(i)
}

#Random number
set.seed(1234)
y = sample(-5:5, 5, replace=F) #randomly choose 5 randoms from -5:5 without replacement
y

for(i in length(y))
{
  if(y[i]>0)
  {
    cat(sprintf("%d is a positive number.\n", y[i]))
  }else if(y[i] < 0)
  {
    cat(sprintf("%d is a negative number.\n", y[i]))
  }else
  {
    cat(sprintf("%d is neither positive nor negative.\n", y[i]))
  }
}

i = 1
while(i < 7)
{
  print(2*i)
  i = i+1
}

#Functions
mycube = function(x)
{
  return(x^3)
}

sum(1:100)
city = c("Beijing", "Lagos", "Paris", "Rio de Janeiro", "San Juan", "Toronto")
temp = c(35L, 88L, 42L, 84L, 81L, 30L)
data.frame(city,temp)



