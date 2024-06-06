<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="UserActivity.aspx.cs" Inherits="Phase3Application.UserActivity" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>User Activity Scores</h1><br>
            <p>
                <asp:GridView ID="top10" runat="server"></asp:GridView>
            </p>
            <asp:Button ID="navButton" runat="server" Text="Friends" OnClick="navButton_Click" />
        </div>
    </form>
</body>
</html>
