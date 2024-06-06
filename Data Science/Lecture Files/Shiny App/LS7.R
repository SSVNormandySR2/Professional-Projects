

library(shiny)
library(plotly)
library(DT)
library(rsconnect)


covid = read.csv("covid_data.csv", sep=";")
covid$Date = as.Date(covid$Date)
covid$Location = as.factor(covid$Location)

ui = fluidPage(
  sidebarLayout(
    sidebarPanel(
      h2("Covid-19 Data"),
      selectInput(
        inputId = "dv", label = "Category",
        choices = c("total_cases","new_cases", "total_deaths", "new_deaths", "total_cases_per_million",
                    "new_cases_per_million", "total_deaths_per_million", "new_deaths_per_million", "icu_patients",
                    "positive_rate", "total_tests", "total_vaccinations", "people_vaccinated"),
        selected = "new_cases"
      ),
      selectInput(inputId = "Locations", "Location(s)",
                  choices = levels(covid$Location),
                  multiple = TRUE,
                  selected = c("United States", "Canada")
                  ),
      dateRangeInput(
        inputId = "date", "Date range",
        start = min(covid$Date),
        end = max(covid$Date)
      ),
      downloadButton(
        outputId = "download_data", label = "Download"
      )
    ),
    mainPanel(
      plotlyOutput(outputId = "plot"), br(),
      em("Disribution for each category by country to compare and contrast"),
      br(), br(), br(),
      DT::dataTableOutput(outputId = "table")
    )
  )
)

server = function(input, output)
{
  filtered_data = reactive({
    subset(covid, Location %in% input$Locations & 
             Date >= input$date[1] &
             Date <= input$date[2])
  })
  output$plot = renderPlotly({
    ggplotly({
      p = ggplot(filtered_data(), aes_string(x = "Date", y = input$dv, color = "Location")) +
        geom_point(alpha = 0.5) + theme(legend.position = "none") +
        ylab("Count") + xlab("Date Range")
      p
    })
  })
  output$table = DT::renderDataTable({
    filtered_data()
  })
  output$download_data = downloadHandler(
    filename = "download_data.csv",
    content = function(file){
      data = filtered_data()
      write.csv(data, file, row.names = F)
    }
  )
}

shinyApp(ui=ui, server=server)
