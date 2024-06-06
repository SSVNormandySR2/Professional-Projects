<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="Phase3Application.Login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Login Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Login</h1><br>
            <asp:Label ID="Label1" runat="server" Text="Email: "></asp:Label>
            <asp:TextBox ID="emailInput" runat="server"></asp:TextBox><br>

            <asp:Label ID="Label2" runat="server" Text="Password: "></asp:Label>
            <asp:TextBox ID="passwordInput" runat="server" TextMode="Password"></asp:TextBox><br>

            <asp:Button ID="loginButton" runat="server" Text="Login" OnClick="loginButton_Click" /><br>

            <asp:Label ID="loginOutput" runat="server" Text="Login Status Here"></asp:Label><br><br>

            <asp:Button ID="createButton" runat="server" Text="Create User" OnClick="createButton_Click" />
        </div>
    </form>
</body>
</html>
