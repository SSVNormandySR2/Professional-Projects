<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="FriendSearch.aspx.cs" Inherits="Phase3Application.FriendSearch" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>Friend Search</h1><br>
            <p>
                <asp:Label ID="Label1" runat="server" Text="Enter first name: "></asp:Label>
                <asp:TextBox ID="fNameInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label2" runat="server" Text="Enter last name: "></asp:Label>
                <asp:TextBox ID="lNameInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="searchButton" runat="server" Text="Search" OnClick="searchButton_Click" /><br>

                <asp:GridView ID="searchOutput" runat="server"></asp:GridView>
            </p>
        </div>
        <div>
            <h1>List and Add Friends</h1><br>
            <p>
                <asp:Label ID="Label3" runat="server" Text="Your Friends: "></asp:Label><br>

                <asp:GridView ID="currentFriends" runat="server"></asp:GridView><br><br>

                <asp:Label ID="Label5" runat="server" Text="Friends with You: "></asp:Label><br>

                <asp:GridView ID="otherFriends" runat="server"></asp:GridView><br><br>

                <asp:Button ID="updateFriends" runat="server" Text="Update Friends List" OnClick="updateFriends_Click" /><br><br>

                <asp:Label ID="Label4" runat="server" Text="Please enter the User ID of a new friend: "></asp:Label>
                <asp:TextBox ID="newFriendInput" runat="server"></asp:TextBox><br>

                <asp:Label ID="Label6" runat="server" Text="Enter today's date (YYYY-MM-DD): "></asp:Label>
                <asp:TextBox ID="docInput" runat="server"></asp:TextBox><br>

                <asp:Button ID="addButton" runat="server" Text="Add New Friend" OnClick="addButton_Click" /><br>

                <asp:Label ID="addOutput" runat="server" Text="Message Here"></asp:Label><br><br>

                <asp:Button ID="navButton" runat="server" Text="View Recommended Friends" OnClick="navButton_Click" />
            </p>
        </div>
    </form>
</body>
</html>
