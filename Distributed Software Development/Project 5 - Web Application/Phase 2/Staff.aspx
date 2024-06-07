<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Staff.aspx.cs" Inherits="VLatonaAssignment8.Staff1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
             <div class="jumbotron">
                <h1>Staff Page</h1>
                <p class="lead">
                    Welcome staff member, you may view member information here.</p>
                 <p class="lead">
                     <asp:Label ID="usernameLabel" runat="server" Text="Username: "></asp:Label>
                 </p>
                 <p class="lead">
                     <asp:TextBox ID="usernameView" runat="server" Height="235px" TextMode="MultiLine" Width="317px"></asp:TextBox>
                 </p>
                 <p class="lead">
                     <asp:Button ID="homeButton" runat="server" OnClick="homeButton_Click" Text="Go to Home Page" />
                 </p>
             </div>
        </div>
    </form>
</body>
</html>
