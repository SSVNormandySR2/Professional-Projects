<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="StaffMgmt.aspx.cs" Inherits="VLatonaAssignment8.Staff" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div class="jumbotron">
                <h1>Staff Management Page - XML File Manipulation</h1>
                <p class="lead">
                    <asp:Label ID="usernameLabel" runat="server" Text="Welcome "></asp:Label>
                </p>
                <p class="lead">You can add new users to the Staff.xml file using the controls below.</p>
                <p class="lead">
                    <asp:Label ID="Label1" runat="server" Text="Staff Username: "></asp:Label>
                    <asp:TextBox ID="usernameInput" runat="server" Width="274px"></asp:TextBox>
                </p>
                <p class="lead">
                    <asp:Label ID="Label2" runat="server" Text="Staff Password: "></asp:Label>
                    <asp:TextBox ID="passwordInput" runat="server" Width="268px"></asp:TextBox>
                    <asp:Button ID="addButton" runat="server" OnClick="addButton_Click" Text="Add Staff" />
                </p>
                <p class="lead">
                    <asp:Label ID="output" runat="server" Text="Status: "></asp:Label>
                </p>
                <p class="lead">
                    <asp:Button ID="defaultButton" runat="server" OnClick="defaultButton_Click" Text="Go to Home Page" />
                </p>
            </div>
        </div>
    </form>
</body>
</html>
