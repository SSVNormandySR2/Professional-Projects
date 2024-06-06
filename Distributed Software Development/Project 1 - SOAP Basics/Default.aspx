<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="SortApp._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>Integer Sorting Web Application</h1>
        <p class="lead">Enter a string of integers separated by commas below and press the &quot;Sort!&quot; button to sort the numbers!</p>
        <p class="lead">Example input format: 1,2,3,4,5 (No Spaces)</p>
        <p>
            <asp:TextBox ID="input" runat="server" Width="556px"></asp:TextBox>
            <asp:Button ID="sortButton" runat="server" OnClick="sortButton_Click" Text="Sort!" />
        </p>
        <p>
            <asp:Label ID="display" runat="server" Text="Sorted integers will be displayed here!"></asp:Label>
        </p>
    </div>

</asp:Content>
