#Vincent Latona

library(shiny) #Import necessary libraries

ui = fluidPage( #Define UI component for the interactive shiny app
    titlePanel("Interactive Probability Distributions"), #Name the shiny app
    sidebarLayout( #Sidebar for definition of panels
        sidebarPanel( #Sidebar for GUI Components
            selectInput( #Drop-down input for distributions
              inputId="distribution",
              label="Select a continuous distribution to be rendered: ",
              selected="Normal",
              choices=c("Normal", "Uniform", "Exponential", "T",
                        "Binomial", "Poisson")
            ), br(),
            helpText("The T distribution will default to n-1 degrees of freedom"), br(),
            numericInput( #Probability for Binomial
              inputId="prob",
              label="For the Binomial distribution, specify a probability of success: ",
              min=0,
              value=0.5,
              max=1,
              step=0.1
            ), br(),
            sliderInput( #Trials for Binomial
              inputId="trials",
              label="For the Binomial distribution, specify a number of trials to simulate: ",
              min=0,
              value=10,
              max=1000,
              step=1
            ), br(),
            numericInput( #Lambda input for Poisson
              inputId="lambda",
              label="For the Poisson distribution, specify a value for lambda (rate): ",
              min=0,
              value=1,
              step=1
            ), br(),
            sliderInput( #Slider for number of observations
              inputId="observations",
              label="Select the number of observations: ",
              min=1,
              max=1500,
              value=100,
              step=1
            ), br(),
            sliderInput( #Slider for number of bins
              inputId="bins",
              label="Select the number of bins: ",
              min=1,
              max=60,
              value=10
            )
        ),
        mainPanel(
          plotOutput("dist")
        )
    )
)

server = function(input, output) #Define logical construction of the shiny app
{ 
  distr = reactive({
    n = input$observations #Get number of observations
    d = ""
    if (input$distribution == "T") #T-distribution case
    {
      d = rt(n, n-1) #Sample randomly from the T-distribution
    } else if (input$distribution == "Binomial") #Binomial-distribution case
    {
      d = rbinom(n, input$trials, input$prob) #Sample randomly from Binomial distribution
    } else if (input$distribution == "Poisson") #Poisson-distribution case
    {
      d = rpois(n, input$lambda) #Sample randomly from the Poisson distribution
    } else
    {
      d = switch(input$distribution, #Switch on Normal, Uniform, Exponential
                 Normal = rnorm,
                 Uniform = runif,
                 Exponential = rexp,
                 rnorm)
      d = d(n) #Sample randomly from selected distribution
    }
  })
  model = reactive({
    n = input$observations #Get number of observations
    interval = (-400:400)/100
    if(input$distribution == "T") #T-distribution case
    {
      d = dt(interval, n-1) #Plot standard T distribution
    } else if (input$distribution == "Binomial")#Binomial-distribution case
    {
      d = dbinom(0:input$trials, input$trials, input$prob) #Plot standard Binomial distribution
    } else if (input$distribution == "Poisson") #Poisson-distribution case
    {
      d = dpois(0:1500, input$lambda) #Plot standard Poisson distribution
    } else
    {
      d = switch(input$distribution, #Switch on Normal, Uniform, Exponential
                 Normal = dnorm,
                 Uniform = dunif,
                 Exponential = dexp,
                 rnorm)
      d = d(interval) #Plot standard selected distribution
    }
  })
  output$dist = renderPlot({
    if (input$distribution == "Binomial") #Plot Binomial histogram
    {
      hist(distr(),
           main=paste("Histogram of", input$distribution, #Add title to histogram
                      "distribution of", input$observations, "observations from",
                      input$trials, "trials with probability", input$prob),
           col="pink", freq=F, breaks=input$bins,
           xlab="Observation Value")
      lines(0:input$trials, model(), col="blue", lwd=2)
      abline(v=mean(distr()), col="red", lwd=2)
      abline(v=sd(distr()), col="green", lwd=2)
      legend("topright", legend=c("Std. Dist.", "Mean", "Std. Dev."), 
             col=c("blue", "red", "green"), lty=1, lwd=2)
    } else if (input$distribution == "Poisson") #Plot Poisson histogram
    {
      hist(distr(),
           main=paste("Histogram of", input$distribution, #Add title to histogram
                      "distribution of", input$observations, "observations with lambda",
                      input$lambda),
           col="pink", freq=F, breaks=input$bins,
           xlab="Observation Value")
      lines(0:1500, model(), col="blue", lwd=2)
      abline(v=mean(distr()), col="red", lwd=2)
      abline(v=sd(distr()), col="green", lwd=2)
      legend("topright", legend=c("Std. Dist.", "Mean", "Std. Dev."), 
             col=c("blue", "red", "green"), lty=1, lwd=2)
    } else #Plot other selected histogram
    {
      hist(distr(),
           main=paste("Histogram of", input$distribution, #Add title to histogram
                      "distribution of", input$observations, "observations"),
           col="pink", freq=F, breaks=input$bins,
           xlab="Observation Value")
      lines((-400:400)/100, model(), col="blue", lwd=2)
      abline(v=mean(distr()), col="red", lwd=2)
      abline(v=sd(distr()), col="green", lwd=2)
      legend("topright", legend=c("Std. Dist.", "Mean", "Std. Dev."), 
             col=c("blue", "red", "green"), lty=1, lwd=2)
    }
  })
}

shinyApp(ui=ui, server=server) #Run the shiny app