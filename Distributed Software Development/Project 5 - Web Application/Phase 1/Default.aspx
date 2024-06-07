<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="VLatonaAssignment8._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>Welcome to the Webstrar 91 Web Application!</h1>
        <p class="lead">Congratulations! You have accessed the Team 91 Web Application deployed at Webstrar. This is the main web page where you can access the functionalities outlined in project 5. Using the controls below, you can access the Member and Staff pages, along with the web services from project 3.</p>
        <p class="lead">
            <asp:Label ID="sessionLabel" runat="server" Text="Current Number of Active Users: "></asp:Label>
        </p>
        <p class="lead">
            <asp:Label ID="usernameLabel" runat="server" Text="Username: "></asp:Label>
        </p>
    </div>

    <div class="row">
        <div class="col-md-4">
            <h2>Login</h2>
            <p>
                Login using the controls on the page below. 
                You may need to create an account to use the web services. </p>
            <p>
                
                <asp:Button ID="loginButton" runat="server" OnClick="loginButton_Click" Text="Go to Login Page" />
                
            </p>
        </div>
        <div class="col-md-4">
            <h2>Access Member Page</h2>
            <p>
                Use the control below to access the Members page. Make sure that you login or create an account to use the member services.
            </p>
            <p>
                
                <asp:Button ID="memberButton" runat="server" OnClick="memberButton_Click" Text="Go to Member Page" />
                
            </p>
        </div>
        <div class="col-md-4">
            <h2>Access Staff Page</h2>
            <p>
                Use the control below to access the Members page. Make sure that you login as a staff member (TA account info).
            </p>
            <p>
                <asp:Label ID="LabelU" runat="server" Text="Admin Username: "></asp:Label>
                <asp:TextBox ID="adminUsernameInput" runat="server" Width="225px"></asp:TextBox>
            </p>
            <p>
                <asp:Label ID="LabelP" runat="server" Text="Admin Password: "></asp:Label>
                <asp:TextBox ID="adminPasswordInput" runat="server" TextMode="Password" Width="226px"></asp:TextBox>
            </p>
            <p>
                <asp:Label ID="adminLoginOutput" runat="server" Text="Login Status: "></asp:Label>
            </p>
            <p>
                
                <asp:Button ID="staffButton" runat="server" OnClick="staffButton_Click" Text="Go to Staff Page" />
                
            </p>
        </div>
    </div>

</asp:Content>
