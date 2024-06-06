<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AlbumView.aspx.cs" Inherits="Phase3Application.AlbumView" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Album Viewer</h1><br>

            <p>
                <asp:Label ID="Label1" runat="server" Text="All Albums: "></asp:Label><br>

                <asp:GridView ID="allAlbums" runat="server"></asp:GridView><br><br>

                <asp:Label ID="Label2" runat="server" Text="Your Albums: "></asp:Label><br>

                <asp:GridView ID="myAlbums" runat="server"></asp:GridView>
            </p>

            <h1>Add Album</h1><br>

            <p>
                <asp:Label ID="Label3" runat="server" Text="Please enter a new album name: "></asp:Label>
                <asp:TextBox ID="albumNameInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label4" runat="server" Text="Please enter today's date (YYYY-MM-DD):"></asp:Label>
                <asp:TextBox ID="dateInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="addButton" runat="server" Text="Add" OnClick="addButton_Click" /><br>

                <asp:Label ID="addOutput" runat="server" Text="Message Here"></asp:Label>
            </p>

            <h1>Delete Album</h1><br>

            <p>
                <asp:Label ID="Label5" runat="server" Text="Please enter the ID number of the album to delete (integer): "></asp:Label>
                <asp:TextBox ID="albumIDInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="deleteButton" runat="server" Text="Delete" OnClick="deleteButton_Click" /><br>

                <asp:Label ID="deleteOutput" runat="server" Text="Message Here"></asp:Label>
            </p>

            <h1>Update Album Details</h1><br>

            <p>
                <asp:Label ID="Label6" runat="server" Text="Enter the album ID of the album to update (integer): "></asp:Label>
                <asp:TextBox ID="updateIDInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label7" runat="server" Text="Please enter a new album name: "></asp:Label>
                <asp:TextBox ID="updateAlbumNameInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="updateButton" runat="server" Text="Update Album Info" OnClick="updateButton_Click" /><br>

                <asp:Label ID="updateOutput" runat="server" Text="Message Here"></asp:Label><br>

                <asp:Button ID="navButton" runat="server" Text="Go to Photos" OnClick="navButton_Click" />
            </p>
        </div>
    </form>
</body>
</html>
