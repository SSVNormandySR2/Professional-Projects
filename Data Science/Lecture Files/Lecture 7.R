#Apply family
set.seed(123)
a = array(sample(2*4*3,))
rowSums(a, dims=2)

head(mtcars)
apply(mtcars, MARGIN=2, FUN=mean) #1=row,2=col
apply(mtcars, MARGIN=1, FUN=mean)

#lapply - output is list
set.seed(1234)
x = list(a=1:5,b=rnorm(10))
x
lapply(x,mean)
x = list(a=1:4,b=rnorm(10),c=rnorm(20, 1),d=rnorm(100,5))
lapply(x,mean)
x = 1:4
lapply(x, runif)

x = list(a=matrix(1:4, 2,2),b=matrix(1:6,3,2))
x
?beaver1
View(beaver1)
beavers = list(b1=beaver1, b2=beaver2)
lapply(beavers, function(x) round(apply(x, MARGIN=2,FUN=mean),2))

#sapply
x = list(a=1:4,b=rnorm(10),c=rnorm(20,1),d=rnorm(100,5))
lapply(x,mean)

s = sapply(x,mean)
s
str(s)
is.vector(s)

#get the mean of each list item and return as a list
lapply(beavers, function(x) round(apply(x,2,mean),2))
#get mean of each list item and simplify the output
sapply(beavers, function(x) round(apply(x,2,mean),2))

#mapply - multivariate apply
list(rep(1,4),rep(2,3),rep(3,2),rep(4,1))
mapply(rep, 1:4, 4:1)

#tapply
df = data.frame(c(7,1,3,4,2,17),c("Feb", "Apr", "May", "Feb", "Apr", "Apr"))
colnames(df) = c("hours", "month")
df

#sum hours by month
tapply(X=df$hours, INDEX=df$month, FUN=sum)
head(mtcars)
#get mean of the mpg by cylinder
tapply(X=mtcars$mpg, INDEX=mtcars$cyl, mean)

#Split
x = c(rnorm(10),runif(10),rnorm(10,1))
levs = gl(3, 10, labels=c("a","b","c"))
split(x, f=levs)

library(datasets)
head(airquality)

s = split(airquality, airquality$Month)
s

lapply(s, function(x) colMeans(x[,c("0zone", "Solar.R", "Wind")], na.rm=T))

#Tidyverse Data Manipulation
install.packages("tidyverse")
install.packages("nycflights13")
library(tidyverse)
library(nycflights13)
str(flights)

#filter
#arrange
#select
#mutate
#summarize
#group_by

#select all flights on Sep 24th
filter(.data=flights, month==9, day==24) #filter acts on rows
sep24 = filter(flights, month==9, day==24)

x = 0.1+0.2
y = 0.3
x == y

sqrt(2)^2 == 2
near(sqrt(2)^2, 2)
NA == NA
Johnwght= 195
Jeffwght = NA
Jeffwght == Johnwght

#all flights that departed in Nov or Dec
filter(flights, month==11 | month==12)

#%in%
novDec = filter(flights, month %in% c(11,12))

df = tibble(x = c(1, NA, 3))
filter(df, x>1)
filter(df, is.na(x)|x>1)