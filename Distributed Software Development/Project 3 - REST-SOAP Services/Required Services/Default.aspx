<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WordServicesTryIt._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>WordServicesTryIt Page</h1>
        <p class="lead">This TryIt page is intended to test the WordCount and WordFilter required services.</p>
    </div>

    <div class="row">
        <div class="col-md-4">
            <h2>WordCount</h2>
            <p>
                This service operation will count the number of occurrences of each unique word in a given text file.</p>
            <p>
                Operation Name: WordCount</p>
            <p>
                Parameter Types: string for filename and string array for file contents</p>
            <p>
                Return Type: string of word count pairs</p>
            <p>
                <asp:Label ID="countPrompt" runat="server" Font-Size="Medium" Text="Please choose a text file to count:"></asp:Label>
            </p>
            <p>
                <asp:FileUpload ID="uploadControl" runat="server" Height="35px" Width="350px" />
                <asp:Label ID="statusLabel" runat="server" Text="Upload status: " Font-Size="Medium"></asp:Label>
            </p>
            <p>
                <asp:Button ID="uploadButton" runat="server" Height="35px" OnClick="uploadButton_Click" Text="Upload!" Width="150px" />
            </p>
            <p>
                &nbsp;<asp:TextBox ID="countDisplay" runat="server" TextMode="MultiLine" Height="238px" Width="459px"></asp:TextBox>
            </p>
        </div>
        <div class="col-md-4">
            <h2>WordFilter</h2>
            <p>
                This service operation will filter all stop words from a given input string.</p>
            <p>
                Operation Name: WordFilter</p>
            <p>
                Parameter Types: string to be filtered </p>
            <p>
                Return Type: string that has been filtered</p>
            <p>
                
            &nbsp;<asp:Label ID="filterLabel" runat="server" Font-Size="Medium" Height="35px" Text="Please enter a string to filter: "></asp:Label>
                <asp:TextBox ID="filterInput" runat="server" Height="35px" Width="466px"></asp:TextBox>
                <asp:Button ID="filterButton" runat="server" Height="35px" OnClick="filterButton_Click" Text="Filter!" />
                
            </p>
            <p>
                
                <asp:Label ID="filterDisplay" runat="server" Font-Size="Small" Text="Filtered string will be displayed here."></asp:Label>
                
            </p>
        </div>
 
    </div>

</asp:Content>
