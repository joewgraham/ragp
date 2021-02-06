
library(tidyverse)
library(reshape2)

data1 <- read.csv("data_001.csv")
data2 <- read.csv("data_01.csv")
data3 <- read.csv("data_02.csv")
data4 <- read.csv("data_04.csv")
data5 <- read.csv("data_06.csv")
data6 <- read.csv("data_07.csv")
data7 <- read.csv("data_08.csv")
data8 <- read.csv("data_09.csv")
data9 <- read.csv("data_10.csv")

all.data <- data.frame(time=data1[,1], cd1=data1[,2], cd2 =data2[,2], cd3=data3[,2], cd4=data4[,2],cd5=data5[,2],cd6=data6[,2],cd7=data7[,2],cd8=data8[,2],cd9=data9[,2])
Molten <- melt(all.data, id.vars = "time")
ggplot(Molten, aes(x = time, y = value, colour = variable)) + geom_line() + xlab('Time') +
  ylab('Voltage')

