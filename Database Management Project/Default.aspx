<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Phase3Application._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <main>
        <section class="row" aria-labelledby="aspnetTitle">
            <h1 id="aspnetTitle">Photo Share Use Cases</h1>
            <p class="lead">In the following Web Application, you can demonstrate the use cases for the Photo Share application.</p>
        </section>

        <div class="row">
            <section>
                <h2>Create an Account</h2>
                <p>
                    <asp:Label ID="Label1" runat="server" Text="*First Name: "></asp:Label>
                    <asp:TextBox ID="fNameInput" runat="server"></asp:TextBox><br>

                    <asp:Label ID="Label2" runat="server" Text="*Last Name: "></asp:Label>
                    <asp:TextBox ID="lNameInput" runat="server"></asp:TextBox><br>

                    <asp:Label ID="Label3" runat="server" Text="*Date of Birth (YYYY-MM-DD):"></asp:Label>
                    <asp:TextBox ID="dobInput" runat="server"></asp:TextBox><br>

                    <asp:Label ID="Label4" runat="server" Text="Hometown: "></asp:Label>
                    <asp:TextBox ID="hometownInput" runat="server"></asp:TextBox><br>

                    <asp:Label ID="Label5" runat="server" Text="Preferred Gender: "></asp:Label>
                    <asp:DropDownList ID="genderInput" runat="server">
                        <asp:ListItem>M</asp:ListItem>
                        <asp:ListItem>F</asp:ListItem>
                        <asp:ListItem Selected="True">N</asp:ListItem>
                    </asp:DropDownList><br>

                    <asp:Label runat="server" Text="*Email: " ID="ctl00"></asp:Label>
                    <asp:TextBox runat="server" ID="emailInput"></asp:TextBox><br>

                    <asp:Label runat="server" Text="*Password: " ID="ctl13">
                    </asp:Label><asp:TextBox runat="server" ID="passwordInput" TextMode="Password"></asp:TextBox><br>

                    <asp:Button ID="Button1" runat="server" Text="Create Account" OnClick="Button1_Click" /><br>
                    <asp:Label ID="createOutput" runat="server" Text="Output Here"></asp:Label>
                </p>
            </section>
            <section>
                <p>
                    <asp:Button ID="NavButton" runat="server" Text="Go to Login Page" OnClick="NavButton_Click" />
                </p>
            </section>
        </div>
    </main>

</asp:Content>
