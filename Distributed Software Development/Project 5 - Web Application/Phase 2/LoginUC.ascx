<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="LoginUC.ascx.cs" Inherits="VLatonaAssignment8.LoginUC" %>
<div class="jumbotron">
        <h1>Login Page</h1>
        <p>Please log into an existing account or create a new one!</p>
        <p>
            <asp:Label ID="Label5" runat="server" Text="Test the Hash Function: "></asp:Label>
            <asp:TextBox ID="hashInput" runat="server" Width="229px"></asp:TextBox>
            <asp:Button ID="hashButton" runat="server" OnClick="hashButton_Click" Text="Hash" />
        </p>
        <p>
            <asp:Label ID="hashOutput" runat="server" Text="Hash here: "></asp:Label>
        </p>
</div>
<p>
    <asp:Label ID="Label1" runat="server" Text="Username: "></asp:Label>
    <asp:TextBox ID="usernameInput" runat="server" Width="241px"></asp:TextBox>
</p>
<p>
    <asp:Label ID="Label2" runat="server" Text="Password: "></asp:Label>
    <asp:TextBox ID="passwordInput" runat="server" Width="239px" TextMode="Password"></asp:TextBox>
    <asp:Label ID="loginOutput" runat="server" Visible="False"></asp:Label>
</p>
<p>
    <asp:Button ID="loginButton" runat="server" OnClick="loginButton_Click" Text="Log In" />
    <asp:Button ID="homeButton" runat="server" OnClick="homeButton_Click" Text="Go to Home Page" />
</p>
<p>
    To create a new account, enter the credentials above, then verify an image below. You will automatically be redirected to the member page.</p>
<p>
    <asp:Image ID="Image1" runat="server" />
    <asp:Label ID="Label3" runat="server" Text="String Length: "></asp:Label>
    <asp:TextBox ID="strLenInput" runat="server" Width="87px"></asp:TextBox>
    <asp:Button ID="imageButton" runat="server" OnClick="imageButton_Click" Text="Get New Image!" />
</p>
<p>
    <asp:Label ID="Label4" runat="server" Text="Enter the string here: "></asp:Label>
    <asp:TextBox ID="verifyStringInput" runat="server" Width="229px"></asp:TextBox>
    <asp:Button ID="verifyButton" runat="server" OnClick="verifyButton_Click" Text="Create New User!" />
</p>
<p>
    <asp:Label ID="verifyOutput" runat="server" Text="Verify Status:"></asp:Label>
</p>

