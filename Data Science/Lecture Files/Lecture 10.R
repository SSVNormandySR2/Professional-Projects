#Simple Linear Regression
getwd()
d1 = read.csv("BMI.csv")

summary(d1)
attach(d1)
plot(PA, BMI, main="Scatter plot of PA vs BMI")

results = lm(BMI~PA, data=d1) #PA is x, BMI is y
results
summary(results)
abline(results) #Add restult line to plot

cor.test(PA, BMI) #Test for correlation between PA and BMI

library(UsingR)
library(plotly)

data("diamond")
head(diamond)
attach(diamond)
plot(diamond$carat, diamond$price)
plot(carat, price, main="Price vs Carat")

mod = lm(price~carat, data=diamond)
mod
summary(mod)
abline(mod)

y = diamond$price
x = diamond$carat
n = length(y)

SSx = sum((x-mean(x))^2)
b1 = sum((x-mean(x))*(y-mean(y)))/SSx
b0 = mean(y)-b1*mean(x)
e = y - (b0+b1*x)
ssq = sum(e^2)/(n-2)
s = sqrt(ssq)
SEb0 = sqrt(ssq*(1/n + mean(x)^2/ SSx))
SEb1 = sqrt(ssq/SSx)
tcrit = qt(p=0.05, df=n-2, lower.tail=F)

Lb0 = b0-SEb0*tcrit
Rb0 = b0+SEb0*tcrit
Lb1 = b1-SEb1*tcrit
Rb1 = b1+SEb1*tcrit

#Data frame with 90% confidence intervals for b0 and b1
CI = data.frame(matrix(c(Lb0, Rb0, Lb1, Rb1), nrow=2, byrow=T), rownames=c("b0", "b1"))
CI

mod = lm(Volume ~ Girth, data=trees)
mod
head(trees)
summary(mod)

x = trees$Girth
y = trees$Volume

xax = list(title="Girth",
           titlefont=list(family="Modern Computer Roman"))
yax = list(title="Volume",
           titlefont=list(family="Modern Computer Roman"),
           range=c(0,80))

fig = plot_ly(x=x, y=y, type="scatter", mode="markers", name="data",
        width=800, height=430) %>%
  add_lines(x=x, y=fitted(mod), name="fitted") %>%
  layout(xaxis=xax, yaxis=yax) %>%
  layout(margin=list(
    l=150, r=50, b=20, t=40
  ))

config(fig, displaylogo=F)
