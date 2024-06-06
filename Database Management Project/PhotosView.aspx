<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="PhotosView.aspx.cs" Inherits="Phase3Application.PhotosView" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Button ID="albumsButton" runat="server" Text="Go to Alubms"  OnClick="albumsButton_Click"/>

            <h1>Photo List</h1><br>

            <p>
                <asp:Label ID="Label1" runat="server" Text="All Photos:"></asp:Label><br>

                <asp:GridView ID="allPhotos" runat="server"></asp:GridView><br><br>

                <asp:Label ID="Label2" runat="server" Text="Your Photos:"></asp:Label><br>

                <asp:GridView ID="yourPhotos" runat="server"></asp:GridView><br><br>

                <asp:Label ID="Label3" runat="server" Text="Please enter an album ID to see the photos in the album: "></asp:Label>

                <asp:TextBox ID="photoAlbumInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="photoFetchButton" runat="server" Text="List Photos" OnClick="photoFetchButton_Click" /><br>

                <asp:Label ID="fetchOutput" runat="server" Text="Output Here"></asp:Label><br>

                <asp:Label ID="Label4" runat="server" Text="Album Photos: "></asp:Label><br>

                <asp:GridView ID="photoList" runat="server"></asp:GridView>
            </p>

            <h1>Photo View/Like/Comment</h1><br>

            <p>
                <asp:Label ID="Label5" runat="server" Text="Please enter the ID of the photo to view: "></asp:Label>

                <asp:TextBox ID="photoIDInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="photoView" runat="server" Text="View Photo" OnClick="photoView_Click" /><br>

                <asp:Label ID="loadOutput" runat="server" Text="Message Here"></asp:Label><br>

                <asp:Image ID="photoImage" runat="server" /><br>

                <asp:Label ID="photoIDOutput" runat="server" Text="Photo ID: "></asp:Label><br>

                <asp:Label ID="photoCaptionOutput" runat="server" Text="Caption: "></asp:Label><br>

                <asp:Label ID="likeOutput" runat="server" Text="Likes: "></asp:Label><br>

                <asp:Label ID="Label6" runat="server" Text="Users who liked this photo: "></asp:Label><br>

                <asp:GridView ID="photoLikes" runat="server"></asp:GridView><br>

                <asp:Label ID="Label7" runat="server" Text="Photo Tags: "></asp:Label><br>

                <asp:GridView ID="photoTags" runat="server"></asp:GridView><br>

                <asp:Label ID="Label8" runat="server" Text="Photo Comments:"></asp:Label><br>

                <asp:GridView ID="photoComments" runat="server"></asp:GridView><br>

                <asp:Button ID="likeButton" runat="server" Text="Like this Photo" OnClick="likeButton_Click" /><br>

                <asp:Label ID="likeMessage" runat="server" Text="Message Here"></asp:Label><br>

                <asp:Label ID="Label9" runat="server" Text="Enter a comment below: "></asp:Label><br>

                <asp:TextBox ID="commentInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label10" runat="server" Text="Enter today's date: "></asp:Label><br>

                <asp:TextBox ID="dateInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="commentButton" runat="server" Text="Add Comment" OnClick="commentButton_Click" /><br>

                <asp:Label ID="commentMessage" runat="server" Text="Message Here"></asp:Label><br><br>

                <asp:Button ID="navButton" runat="server" Text="Go to Photo Adder" OnClick="navButton_Click" /><br>
            </p>

            <p>
                <asp:Label ID="Label11" runat="server" Text="All Likes: "></asp:Label><br>

                <asp:GridView ID="allLikes" runat="server"></asp:GridView><br>

                <asp:Label ID="Label12" runat="server" Text="All Comments: "></asp:Label><br>

                <asp:GridView ID="allComments" runat="server"></asp:GridView><br>

                <asp:Label ID="Label13" runat="server" Text="All Tags: "></asp:Label><br>

                <asp:GridView ID="allTags" runat="server"></asp:GridView>
            </p>
        </div>
    </form>
</body>
</html>