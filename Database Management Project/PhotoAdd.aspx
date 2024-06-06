<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="PhotoAdd.aspx.cs" Inherits="Phase3Application.PhotoAdd" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Add Photo</h1><br>

            <p>
                <asp:Button ID="viewPhotosButton" runat="server" Text="View Photos" OnClick="viewPhotosButton_Click" /><br>

                <asp:Label ID="Label1" runat="server" Text="Your Albums: "></asp:Label><br>

                <asp:GridView ID="userAlbums" runat="server"></asp:GridView><br><br>

                <asp:Label ID="Label2" runat="server" Text="Your Photos: "></asp:Label><br>

                <asp:GridView ID="userPhotos" runat="server"></asp:GridView>
            </p>

            <p>
                <asp:Label ID="Label3" runat="server" Text="Please enter an album ID to add to: "></asp:Label>

                <asp:TextBox ID="albumInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label4" runat="server" Text="Enter a caption for the photo: "></asp:Label>

                <asp:TextBox ID="captionInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label5" runat="server" Text="Enter the link for your photo: "></asp:Label>

                <asp:TextBox ID="photoLoc" runat="server"></asp:TextBox><br>

                <asp:Button ID="addPhotoButton" runat="server" Text="Add Photo" OnClick="addPhotoButton_Click" /><br>

                <asp:Label ID="addMessage" runat="server" Text="Message Here"></asp:Label>
            </p>

            <h1>Add Tags to Your Photos</h1><br>

            <p>
                <asp:Label ID="Label8" runat="server" Text="Enter the photo ID to add to: "></asp:Label>

                <asp:TextBox ID="photoIDInput" runat="server"></asp:TextBox><br>
                
                <asp:Label ID="Label7" runat="server" Text="Add a tag: "></asp:Label>

                <asp:TextBox ID="tagInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="tagButton" runat="server" Text="Add Tag" OnClick="tagButton_Click" /><br>

                <asp:Label ID="tagMessage" runat="server" Text="Message Here"></asp:Label>
            </p>

            <h1>Delete Photo</h1><br>

            <p>
                <asp:Label ID="Label6" runat="server" Text="Enter the photo ID to delete: "></asp:Label>

                <asp:TextBox ID="deleteInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="deletePhotoButton" runat="server" Text="Delete Photo" OnClick="deletePhotoButton_Click" /><br>

                <asp:Label ID="deleteMessage" runat="server" Text="Message Here"></asp:Label>
            </p>

            <asp:Button ID="navButton" runat="server" Text="View Most Popular Tags" OnClick="navButton_Click" />
        </div>
    </form>
</body>
</html>
