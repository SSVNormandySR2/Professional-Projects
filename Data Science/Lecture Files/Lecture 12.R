library(plotly)
library(UsingR)
library(tidyverse)
library(ggplot2)
attach(mpg)
data(mpg)
str(mpg)

ggplot(mpg, aes(x=displ, y=hwy)) + geom_point()
ggplot(mpg, aes(x=displ, y=hwy, color=class)) + geom_point(alpha=5)

g = ggplot(mpg, aes(x=displ, y=hwy, color=class)) +
  geom_point(alpha=0.5) + 
  stat_smooth(method="lm", se=F, fill=NA, formula=y~poly(x,3), color="blue") +
  stat_smooth(method="loess", se=F, color="red")
g

ggplotly(g) %>%
  layout(margin=list(l=200, t=60))

ggplot(mpg, aes(displ,hwy)) +
  geom_point(aes(color= class, shape = drv, size=cty)) +
  scale_shape_discrete("drive train")
scale_shape_continuous("city mileage")
  
#barplot
?geom_bar
ggplot(data=mpg, aes(x=class)) + geom_bar(stat="count", width=0.7, fill="steelblue") +
  theme_classic()

survey = data.frame(fruit=c("Apple", "Banana", "Grapes", "Kiwi", "Orange", "Pears"),
                    people=c(40, 50, 30, 15, 35, 20))
survey
ggplot(survey, aes(x=fruit, y=people, fill="red")) + geom_bar(stat="identity")

g = ggplot(survey, aes(x=fruit, y=people, fill=fruit)) + geom_bar(stat="identity") +
  theme(axis.title.x = element_text(face="bold", color="#993333", size=12, angle=60, hjust=0.8))
g

#Interactive bar
ggplotly(g) %>%
  layout(margin=list(l=150, t=80)) %>%
  config(displaylogo=F)

#Logarithmic scale
msleep
g = ggplot(msleep, aes(x=brainwt, y=bodywt)) + 
  scale_x_log10() + 
  scale_y_log10() +
  geom_point(aes(color=vore)) +
  scale_color_manual(values=c("red", "orange", "green", "blue"), na.value="grey50")
g

#Facetting
p = ggplot(mpg, aes(cty, hwy)) + 
  geom_jitter(width=0.1, height=0.1)
p + facet_wrap(~cyl)

df = data.frame(
  x=rnorm(180, c(0,2,4)),
  y=rnorm(180, c(1,2,1)),
  z=letters[1:3]
)
head(df)

ggplot(df, aes(x,y)) + geom_point(aes(color=z), size=3, alpha=0.5)
ggplot(df, aes(x,y)) + geom_point() +
  geom_jitter(width=0.1, height=0.1) + facet_wrap(~z)

#Comparing categories in single panel
df_sum = df %>% group_by(z) %>% 
  summarise(x=mean(x), y=mean(y)) %>%
  rename(Z=z)
df_sum
ggplot(df, aes(x,y)) + geom_point() + geom_point(data=df_sum, aes(color=Z), size=3) +
  facet_wrap(~z)

#overlapping data across facets
df2 = dplyr::select(df, -z)
ggplot(df, aes(x,y)) + geom_point(data=df2, color="grey70", size=3, alpha=0.5) +
  geom_point(aes(color=z), size=3) + facet_wrap(~z)

#Animation
library(animation)
ani.options(interval=0.2, nmax=100)
sample_size=50
conf.int(level=0.9, size=sample_size, 
         main=paste("Simulaiton of ", ani.options()$nmax, 
                    "Confidence Intervals\nEach sample size:n", sample_size))

set.seed(123)
n = 10
x = rnorm(n)
y = rnorm(n)
ani.options(nmax=60)
for(i in seq_len(ani.options("nmax")))
{
  dev.hold()
  plot(x, y, xlim=c(-20,20), col=1:n,pch=19, cex=2)
  x = x + rnorm(n)
  y = y + rnorm(n)
  ani.pause()
}

library(gganimate)
library(gapminder)
library(ggplot2)