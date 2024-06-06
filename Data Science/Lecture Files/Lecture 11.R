#Imports for plotly
library(plotly)
library(UsingR)
data(mtcars)
attach(mtcars)

xax = list(title="Weight", titlefont=list(family="Modern Computer Roman")) #x-axis
yax = list(title="Miles per Gallon", titlefont=list(family="Modern Computer Roman")) #y-axis

plot_ly(mtcars, x=wt, y=mpg, type="scatter", mode="markers",color=disp) %>% 
  layout(xaxis=xax, yaxis=yax)

xax = list(title="Weight", titlefont=list(family="Modern Computer Roman")) #x-axis
yax = list(title="Miles per Gallon", titlefont=list(family="Modern Computer Roman")) #y-axis

plot_ly(mtcars, x=wt, y=mpg, mode="markers", color=as.factor(cyl), size=hp,
        width=600, height=350) %>%
  layout(xaxis=xax, yaxis=yax)

set.seed(123)
myX = rnorm(100, mean=30, sd=5)
myY = rnorm(100)
myZ = rnorm(100, mean=15, sd=12)

plot_ly(x=myX, y=myY, z=myZ, type="scatter3d", mode="markers",
        color=myZ) %>%
  hide_colorbar()

x = seq(-6, 6, 0.5)
y = seq(-2, 2, 0.5)

X = matrix(rep(x, length(y)), nrow=length(y), byrow=T)
Y = matrix(rep(y, length(x)), ncol=length(x), byrow=F)
Z = sin(X+1) + Y^2
Zp = 0.6*X + 0.8

fig = plot_ly(x=X, y=Y, z=Z, showscale=F, width=800, height=550) %>%
  add_surface(contours=list(
    z=list(show=T, 
           usecolormap=T, 
           highlightcolor="#ff0000", 
           project=list(z=T)
           )
    )
    )

fig = fig %>% layout(list(
  scene=list(camera=list(eye=list(x=1.87, y=0.88, z=-0.6)))
))

fig = fig %>%
  add_surface(z=Zp)
fig

#ggplot2
library(ggplot2)
g = ggplot(trees, aes(x=Girth, y=Volume)) + geom_point()
g

g + geom_smooth(method="lm") + coord_cartesian(ylim=c(0, 80))
g + geom_smooth(method="lm", level=0.99) + coord_cartesian(ylim=c(0, 80)) #set Confidence level to 99%

g + geom_smooth(method="lm", se=F) #No std error

g + geom_smooth(method="lm", se=F) + theme_bw()

head(diamonds)
g = ggplot(diamonds, aes(x=carat, y=price)) + geom_point(aes(color=clarity))
g

library(dplyr)
head(airquality, 3)

month = recode_factor(airquality$Month, '5'="May", '6'="June", '7'="July", '8'="August", '9'="September")
air = airquality[, c("Ozone", "Solar.R", "Wind")]
air$Month = month
air = air[!is.na(air$Ozone) & !is.na(air$Wind),]
g = ggplot(air, aes(x=Wind, y=Ozone, color=Month)) + geom_smooth(method="lm", se=F, color="blue") +
  geom_point(alpha=5) + coord_cartesian(ylim=c(0, 175)) #alpha for transparency
g

g = ggplot(air, aes(x=Wind, y=Ozone, color=Month)) +
  geom_point() + 
  stat_smooth(method="lm", se=F, fill=NA, formula=y~poly(x,2), color="blue") +
  stat_smooth(method="loess", se=F, color="red")
g
