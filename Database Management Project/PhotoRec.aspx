<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="PhotoRec.aspx.cs" Inherits="Phase3Application.PhotoRec" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Recommended Photos</h1><br>

            <p>
                <asp:Label ID="Label1" runat="server" Text="Recommended Photos:"></asp:Label><br>

                <asp:GridView ID="recommended" runat="server"></asp:GridView>
            </p>

            <p>
                <asp:Label ID="Label5" runat="server" Text="Enter a photo ID to view: "></asp:Label>

                <asp:TextBox ID="photoInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="photoSearch" runat="server" Text="View Photo" OnClick="photoSearch_Click" /><br>

                <asp:Label ID="photoViewMessage" runat="server" Text="Message Here"></asp:Label><br>

                <asp:Image ID="photoImage" runat="server" />
            </p>

            <asp:Button ID="logoutButton" runat="server" Text="Log Out" OnClick="logoutButton_Click" />
        </div>
    </form>
</body>
</html>
