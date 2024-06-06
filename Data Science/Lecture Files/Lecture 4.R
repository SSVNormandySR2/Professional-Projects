#Function practice
y = 10
f = function(x)
{
  y^2 + g(x)
}

g = function(x)
{
  x*y
}

f(3)
x = seq(-10,10,by=0.1)
y1=sin(x)
y2=cos(x)
plot(x, y1, type="l",col="blue")
lines(x, y2, col="red",lty=4)
abline(a=0,b=0.1,col="green")
abline(v=5,col="magenta", lwd=4, lty=3)
points(x=seq(-10,10,by=1), y=exp(seq(-10,10,by=1)),col="black", pch=3)

#Histograms
?mtcars
dim(mtcars)
head(mtcars)

hist(mtcars$mpg)
hist(mtcars$mpg, breaks=12,col="red") #breaks is the number of bins


#Normal Distribution
#Sample size n = 100
set.seed(12)
x = rnorm(n=100, mean=0, sd=1)
hist(x) #xlim=c(-4,4)


#Sample size n = 500
set.seed(12)
x = rnorm(n=500, mean=0, sd=1)
hist(x) #xlim=c(-4,4)
hist(x, freq=F, xlim=c(-4,4))

#Sample size n = 1000
set.seed(12)
x = rnorm(n=1000, mean=0, sd=1)
hist(x) #xlim=c(-4,4)
hist(x, freq=F, xlim=c(-4,4))

#CLT states that as n approaches inf, it becomes normal
png("four-hists.png", width=1000, height=500,) #create png
t = (-400:400)/100
set.seed(12)
par(mfrow=c(2,2))
for (n in c(100, 500, 1000, 5000)) 
{
  x = rnorm(n, mean=0, sd=1)
  hist(x, breaks=50, freq=F,main=paste("n",n), xlim=c(-4,4), ylim=c(0,0.8))
  lines(t,dnorm(t, 0, 1),lwd=2,col="blue") #dnorm is pdf for normal
}
dev.off()

#Expected Vlaue, Sample Mean, Sample Variance, KDE - Kernel Density Estimation
mean(mtcars$mpg)
var(mtcars$mpg)
sd(mtcars$mpg)

?dnorm
