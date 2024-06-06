<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="FriendRecommendations.aspx.cs" Inherits="Phase3Application.FriendRecommendations" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Recommended Friends</h1><br><br>
            <p>
                <asp:Label ID="Label1" runat="server" Text="Recommended Friends: "></asp:Label><br>
                <asp:GridView ID="dispTable" runat="server"></asp:GridView><br><br>

                <asp:Button ID="navButton" runat="server" Text="Go to Albums" OnClick="navButton_Click" />
            </p>
        </div>
    </form>
</body>
</html>
