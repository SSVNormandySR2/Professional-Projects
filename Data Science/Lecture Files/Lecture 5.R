#Binomial Distribution
#n = sample, size or trials

x = rbinom(n=50, size=10, prob=0.1)
hist(x, freq=F,breaks=seq(-0.5,10.5,1))


x = rbinom(n=50, size=10, prob=0.5)
hist(x, freq=F,breaks=seq(-0.5,10.5,1))

#Kernel Density Estimation
?mtcars
attach(mtcars)

dsty = density(mtcars$mpg, kernel="gaussian")
str(dsty)
x = mtcars$mpg
hist(x, freq=F,col="red",xlab="Miles Per Gallon", main="Histogram with normal curve")

dsty = density(mtcars$mpg, kernel="gaussian")
lines(dsty$x, dsty$y, type="l", lwd=2)

#Boxplots
?airquality
data("airquality")
str(airquality)

air = airquality
head(air)
unique(air$Month)
attach(air) #attach will keep the dataframe in history
par(mfrow=c(2,1),mai=c(0.5,0.6,0.5,0.6)) #mai is for margins
hist(Solar.R, xlim=c(0,350))
boxplot(Solar.R, horizontal=T,main="Boxplot of Solar.R", ylim=c(0,350),axes=F)
axis(2) #Places measures in designated spots

median(Solar.R, na.rm=T)
quantile(Solar.R, probs=seq(0,1,0.25),na.rm=T)
c(min(Solar.R,na.rm=T), max(Solar.R, na.rm=T))
summary(Solar.R) #Summarizes min, max, med, mean, quantiles (EDA - Exploratory Data Analysis)

library(dplyr)
months = recode_factor(air$Month, '5'="May", '6'="June", '7'="July", '8'="August", '9'="September") #Recode for dfs
unique(months)
boxplot(Solar.R~months,data=air,col=topo.colors(length(unique(months))))

boxplot(Solar.R~months, data=air,horizontal=T,col=c("purple","blue","green","yellow","red"))
legend("topright",legend=c("May","Jun","Jul","Aug","Sep"),fill=c("purple","blue","green","yellow","red"))

boxplot(Solar.R~months,data=air,col=topo.colors(length(unique(months))))
abline(h=mean(air$Solar.R,na.rm=T),col="red",lty="dashed",lwd=2)

#Barplots
data("mtcars")
head(mtcars)
counts = table(mtcars$cyl)
counts = as.vector(counts)
xx = barplot(counts, main="Car distribution by Cylinders", xlab="Number of Cylinders", ylim=c(0,max(counts)+3), col="deeppink")
text(x=xx,y=counts+2, labels=as.character(counts),cex=1.5, col="darkblue")
counts = table(mtcars$vs, mtcars$cyl)
barplot(counts, main="car dist by cylinders vs v-shaped engine",
         xlab="Number of cylinders", col=c("darkblue", "deeppink"),
         xlim=c(0,4.5), legend = rownames(counts))
cex?


counts = table(mtcars$cyl, mtcars$vs)
barplot(counts, main="car dist by cylinders vs engine shape", 
        xlab="number of cylinders", col=c("darkblue", "deeppink"),
        xlim=c(0,8),
        legend=rownames(counts),beside=T)



