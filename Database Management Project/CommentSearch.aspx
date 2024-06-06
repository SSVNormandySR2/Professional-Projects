<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="CommentSearch.aspx.cs" Inherits="Phase3Application.CommentSearch" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Search on Comments</h1><br>

            <p>
                <asp:Label ID="Label1" runat="server" Text="Enter a comment to search: "></asp:Label>

                <asp:TextBox ID="commentInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="commentSearchButton" runat="server" Text="Search Comment" OnClick="commentSearchButton_Click" /><br>

                <asp:Label ID="commentMessage" runat="server" Text="Message Here"></asp:Label><br>

                <asp:GridView ID="comments" runat="server"></asp:GridView>
            </p>

            <asp:Button ID="navButton" runat="server" Text="Photo Recommendations" OnClick="navButton_Click" />

        </div>
    </form>
</body>
</html>
