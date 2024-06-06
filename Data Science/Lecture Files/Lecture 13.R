library(ggplot2)
library(ggpubr)

#Maps
library(plotly)
library(ggplot2)
library(tidyverse)
library(dplyr)

head(USArrests)
df = data.frame(murder = USArrests$Murder, state = tolower(rownames(USArrests)))
map = ggplot2::map_data("state")
m = ggplot(data=df, aes(fill=murder)) + 
  geom_map(aes(map_id=state), map=map) +
  expand_limits(x=map$long, y=map$lat)

ggplotly(m) %>%
  layout(xaxis=list(title=""), yaxis=list(title=""))

#AZ Map
az_counties = map_data("county", "arizona") %>%
  select(lon=long, lat, group, id=subregion)
head(az_counties)

ggplot(az_counties, aes(lon, lat, group=group)) +
  geom_polygon(fill="white", color="blue") +
  coord_quickmap() + theme_classic() +
  theme(axis.ticks=element_blank(),
        axis.line=element_blank(),
        axis.title=element_blank())
library(usmap)

m1 = plot_usmap(data=statepop, values="pop_2015", color="white") +
  scale_fill_continuous(name="Population(2015)", label=scales::comma) +
  theme(legend.position="right")

ggplotly(m1)

m2 = plot_usmap(data=statepop, values="pop_2015", color="white") +
  scale_fill_gradientn(name="Population(2015)", color=rev(rainbow(7))) +
  theme(legend.position="right")

ggplotly(m2)