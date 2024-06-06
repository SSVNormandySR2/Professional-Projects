<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="TagSearch.aspx.cs" Inherits="Phase3Application.TagSearch" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Photos by Tag Name</h1><br>

            <p>
                <asp:Label ID="Label4" runat="server" Text="Possible Tags:"></asp:Label><br>

                <asp:GridView ID="allTags" runat="server"></asp:GridView><br>

                <asp:Label ID="Label3" runat="server" Text="Enter a tag to search: "></asp:Label>

                <asp:TextBox ID="tagInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="searchButton" runat="server" Text="Find Photos" OnClick="searchButton_Click" /><br>

                <asp:Label ID="tagSearchMessage" runat="server" Text="Message Here"></asp:Label><br><br>
                
                <asp:Label ID="Label1" runat="server" Text="All Photos:"></asp:Label><br>

                <asp:GridView ID="allPhotos" runat="server"></asp:GridView><br>

                <asp:Label ID="Label2" runat="server" Text="Your Photos: "></asp:Label><br>

                <asp:GridView ID="yourPhotos" runat="server"></asp:GridView><br>
            </p>

            <h1>Tag Search</h1><br>

            <p>
                <asp:Label ID="Label6" runat="server" Text="Enter a list of tags to search: "></asp:Label>

                <asp:TextBox ID="tagListInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="listSearchButton" runat="server" Text="Search List" OnClick="listSearchButton_Click" /><br>

                <asp:Label ID="listSearchMessage" runat="server" Text="Message Here"></asp:Label><br>

                <asp:ListBox ID="intersectList" runat="server"></asp:ListBox>
            </p>

            <p>
                <asp:Label ID="Label5" runat="server" Text="Enter a photo ID to view: "></asp:Label>

                <asp:TextBox ID="photoInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="photoSearch" runat="server" Text="View Photo" OnClick="photoSearch_Click" /><br>

                <asp:Label ID="photoViewMessage" runat="server" Text="Message Here"></asp:Label><br>

                <asp:Image ID="photoImage" runat="server" />
            </p>

            <asp:Button ID="navButton" runat="server" Text="Search Comments" OnClick="navButton_Click" /><br><br>
        </div>
    </form>
</body>
</html>
