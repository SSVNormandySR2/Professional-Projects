#arrange() - column manipulation
library(dplyr)
library(nycflights13)
library(tidyverse)

arrange(flights,year,month,day)
arrange(flights,desc(dep_delay)) #missing values are always at the end

df= tibble(x = c(5,2,NA))
arrange(df, x)

#select() - columns by name
select(flights,year,month,day)
select(flights, year:day)
select(flights, -(year:day))

#helpers - rename, group-by, everything
rename(flights, tail_num = tailnum)
select(flights, time_hour, air_time, everything())

#Mutate : Transforming columns
flights_sml = select(flights, year:day, ends_with("delay"), distance, air_time)
flights_sml

flights2 = mutate(flights_sml, gain = arr_delay-dep_delay, speed = (distance/air_time)*60)

#summarize() - uses group_by()
summarize(flights, delay=mean(dep_delay, na.rm=T))
by_day = group_by(flights, year, month, day)
summarize(by_day, delay=mean(dep_delay, na.rm=T))

#Pipe %>%
flights2 = select(flights, year:day, ends_with("delay"), origin)
flights3 = mutate(flights2, gain = dep_delay - arr_delay)
flights4 = group_by(flights3, origin)
flightSummary = summarize(flights4, mean(dep_delay, na.rm=T),mean(gain, na.rm=T))
flightSummary

flightSummary = summarize(
  group_by(
    mutate(
      select(
        flights, year:day, ends_with("delay"), origin), 
      gain = dep_delay-arr_delay),
    origin),
  mean(dep_delay, na.rm=T), mean(gain, na.rm=T)
  )
flightSummary

flightSummary = flights %>%
  select(year:day, ends_with("delay"),origin) %>%
  mutate(gain = dep_delay-arr_delay) %>% 
  group_by(origin) %>%
  summarize(mean(dep_delay, na.rm=T), mean(gain, na.rm=T))
flightSummary

#Tibble
?iris
head(iris)
str(iris)
as_tibble(iris)

tibble(x = 1:5, y = 1, z = x^2+y)

#importing data - first change the working directory to read or use import dataset
getwd()
d1 = read.csv("Absenteeism_at_work.csv")
str(d1)
View(d1)

#R Markdown