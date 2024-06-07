<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="StaffLogin.aspx.cs" Inherits="VLatonaAssignment8.StaffLogin" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div class="jumbotron">
                <h1>Staff Login Page</h1>
                <p class="lead">
                    Welcome, please log into a staff account created by an administrator.</p>
                <p class="lead">
                    <asp:Label ID="usernameLabel" runat="server" Text="Username: "></asp:Label>
                    <asp:TextBox ID="staffUsernameInput" runat="server" Width="301px"></asp:TextBox>
                </p>
                <p class="lead">
                    <asp:Label ID="Label1" runat="server" Text="Password: "></asp:Label>
                    <asp:TextBox ID="staffPasswordInput" runat="server" Width="292px" TextMode="Password"></asp:TextBox>
                    <asp:Label ID="loginOutput" runat="server" Text="Login Result:"></asp:Label>
                </p>
                <p class="lead">
                    <asp:Button ID="loginButton" runat="server" OnClick="loginButton_Click" Text="Staff Login" />
                </p>
                <p class="lead">
                    <asp:Button ID="homeButton" runat="server" OnClick="homeButton_Click" Text="Go to Home Page" />
                </p>
            </div>
        </div>
    </form>
</body>
</html>
