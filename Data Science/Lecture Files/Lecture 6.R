#Pie charts
counts = as.vector(table(mtcars$cyl))
label = c("4", "6", "8")
pct = round((counts/sum(counts))*100) #get relative percentage
label = paste(label, pct, sep=";")
label = paste(label, "%", sep="")
pie(counts, labels=label, col=rainbow(length(label)), main="Pie Chart of Cylinders")

library(plotrix)
counts = as.vector(table(mtcars$cyl))
lbls = c("4", "6", "8")
pct = round((counts/sum(counts))*100)
lbls = paste(lbls, pct, sep=";")
lbls = paste(lbls, "%", sep="")
pie3D(counts, labels=lbls, col=rainbow(length(lbls)),explode=0.1,main="Pie Chart of Cylinders")

#Colors
?colors

hist(mtcars$mpg, breaks=12, col=rgb(1,0,1))
hist(mtcars$mpg, breaks=12, col=rgb(1,0,1,alpha=0.6))
hist(mtcars$mpg, breaks=12, col=rgb(1,0,1,alpha=0.5,maxColorValue=255))

#Defining a vector of magenta, maroon, gold, and cyan
mycolors = c("#FF00FF", "#8C1D40", "#FFC627", "#00FFFF")
png("four-hists-with-colors.png", width=1000,height=500)
par(mfrow=c(2,2))
t = (-400:400)/100
set.seed(12)
iter= 0
for (n in c(100, 500, 1000, 5000))
{
  iter = iter+1
  x = rnorm(n = n, mean = 0, sd=1)
  hist(x, breaks=50, freq=F,main=paste("n=",n), col=mycolors[iter], 
       xlim=c(-4,4),ylim=c(0,0.8))
  lines(t,dnorm(t,0,1),lwd=2,col="blue")
}
dev.off()

#vector recycling
v1 = c(3,8,4,5,0,11)
v2 = c(4,11)
v1+v2 #recycles the values from the smaller vector to be used again in the arithmetic

#Matrix
M = matrix(c(3:14), nrow=4,byrow=T)
M
M = matrix(c(3:14), nrow=4)
M

rownames = c("r1", "r2", "r3", "r4")
colnames = c ("c1", "c2", "c3")
P = matrix(c(3:14), nrow=4, byrow=T, dimnames = list(rownames,colnames))
P

#Arrays
v1 = c(5,9,3)
v2 = c(10,11,12,13,14,15)
column.names = c("col1", "col2", "col3")
row.names = c("row1", "row2", "row3")
matrix.names = c("M1","M2")
result = array(c(v1,v2),dim=c(3,3,2),dimnames=list(row.names,column.names,matrix.names))
result

result[3,2,1]

#Apply family: apply, lapply, sapply, mapply, tapply
M = matrix(c(1:9),nrow=3,byrow=T)
M[2:2] = -1
M
apply(X=M,MARGIN=1,FUN=sum) #sum of row
apply(X=M,MARGIN=2,FUN=sum) #sum of col

#Quantiles
x = matrix(rnorm(30),5,6)
x

apply(x,1,quantile,probs=c(0.25,0.75)) #generates 25% and 75% quantile

set.seed(123)
a = array(sample(2*4*3,replace=T),dim=c(2,4,3))
a