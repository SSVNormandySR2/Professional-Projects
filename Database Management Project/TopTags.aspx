<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="TopTags.aspx.cs" Inherits="Phase3Application.TopTags" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Most Popular Tags</h1>

            <p>
                <asp:GridView ID="topTags" runat="server"></asp:GridView><br><br>

                <asp:Button ID="navButton" runat="server" Text="Search Tags" OnClick="navButton_Click" />
            </p>
        </div>
    </form>
</body>
</html>
