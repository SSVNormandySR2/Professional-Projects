/*
 * Vincent Latona
 */

import java.util.regex.Pattern;
import java.util.concurrent.TimeUnit;
import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import org.openqa.selenium.*;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;

public class calcTest 
{
  private WebDriver driver;
  private String baseUrl;
  private boolean acceptNextAlert = true;
  private StringBuffer verificationErrors = new StringBuffer();

  @Before
  public void setUp() throws Exception {
	    System.setProperty("webdriver.chrome.driver","C:\\Apps\\chromedriver_win32\\chromedriver.exe");
         driver = new ChromeDriver();

    baseUrl = "http://webstrar99.fulton.asu.edu/";
    driver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
  }

  @Test
  public void testAdd() throws Exception 
  {
    driver.get(baseUrl + "/page2/Default.aspx"); //Navigate to webpage
    driver.findElement(By.name("num1")).clear(); //Clear num1 input field
    driver.findElement(By.name("num1")).sendKeys("6"); //Enter 6 into num1 input field
    driver.findElement(By.name("num2")).clear(); //Clear num2 input field
    driver.findElement(By.name("num2")).sendKeys("5"); //Enter 5 into num2 input field
    WebElement radioButton = driver.findElement(By.id("add")); //Find add radio button
    radioButton.click(); //Select add
    driver.findElement(By.name("calc")).click(); //Click the calc button
    assertEquals("11", driver.findElement(By.name("res")).getAttribute("value")); //Test output against expected output
  }
  
  @Test
  public void testSub()
  {
	  driver.get(baseUrl + "/page2/Default.aspx"); //Navigate to webpage
	  driver.findElement(By.name("num1")).clear(); //Clear num1 input field
	  driver.findElement(By.name("num1")).sendKeys("6"); //Enter 6 into num1 input field
	  driver.findElement(By.name("num2")).clear(); //Clear num2 input field
	  driver.findElement(By.name("num2")).sendKeys("0"); //Enter 0 into num2 input field
	  WebElement radioButton = driver.findElement(By.id("sub")); //Find sub radio button
	  radioButton.click(); //Select sub
	  driver.findElement(By.name("calc")).click(); //Click the calc button
	  assertEquals("6", driver.findElement(By.name("res")).getAttribute("value")); //Test output against expected output
  }
  
  @Test
  public void testMult()
  {
	  driver.get(baseUrl + "/page2/Default.aspx"); //Navigate to webpage
	  driver.findElement(By.name("num1")).clear(); //Clear num1 input field
	  driver.findElement(By.name("num1")).sendKeys("6"); //Enter 6 into num1 input field
	  driver.findElement(By.name("num2")).clear(); //Clear num2 input field
	  driver.findElement(By.name("num2")).sendKeys("4"); //Enter 4 into num2 input field
	  WebElement radioButton = driver.findElement(By.id("mul")); //Find mul radio button
	  radioButton.click(); //Select mul
	  driver.findElement(By.name("calc")).click(); //Click the calc button
	  assertEquals("24", driver.findElement(By.name("res")).getAttribute("value")); //Test output against expected output
  }
  
  @Test
  public void testDiv()
  {
	  driver.get(baseUrl + "/page2/Default.aspx"); //Navigate to webpage
	  driver.findElement(By.name("num1")).clear(); //Clear num1 input field
	  driver.findElement(By.name("num1")).sendKeys("56"); //Enter 56 into num1 input field
	  driver.findElement(By.name("num2")).clear(); //Clear num2 input field
	  driver.findElement(By.name("num2")).sendKeys("7"); //Enter 7 into num2 input field
	  WebElement radioButton = driver.findElement(By.id("div")); //Find div radio button
	  radioButton.click(); //Select div
	  driver.findElement(By.name("calc")).click(); //Click the calc button
	  assertEquals("8", driver.findElement(By.name("res")).getAttribute("value")); //Test output against expected output
  }
}