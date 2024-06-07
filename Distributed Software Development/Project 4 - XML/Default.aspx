<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="XMLWebApp._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>XML Services TryIt</h1>
        <p class="lead">This TryIt ASPX page allows for testing of XML Operations.</p>
    </div>

    <div class="row">
        <div class="col-md-4">
            <h2>XML File Validation</h2>
            <p>
                This operation allows you to validate an XML file against an XML Schema file.</p>
            <p>
                <asp:Label ID="Label1" runat="server" Text="Please enter the URL of an XML file: "></asp:Label>
                <asp:TextBox ID="xmlFileInput" runat="server" Width="291px"></asp:TextBox>
            </p>
            <p>
                <asp:Label ID="Label2" runat="server" Text="Please enter the URL of an XML Schema file: "></asp:Label>
                <asp:TextBox ID="xsdFileInput" runat="server" Width="329px"></asp:TextBox>
                <asp:Button ID="validationButton" runat="server" OnClick="validationButton_Click" Text="Validate!" />
            </p>
            <p>
                <asp:TextBox ID="validationOutput" runat="server" Height="315px" TextMode="MultiLine" Width="895px"></asp:TextBox>
            </p>
            <p>
                &nbsp;</p>
        </div>
        <div class="col-md-4">
            <h2>XML File Search</h2>
            <p>
                This operation allows you to search an XML file for specific elements/attributes, returning all children of the found element/attribute.</p>
            <p>
                <asp:Label ID="Label3" runat="server" Text="Please enter the URL of an XML file: "></asp:Label>
                <asp:TextBox ID="searchXmlInput" runat="server" Width="382px"></asp:TextBox>
            </p>
            <p>
                <asp:Label ID="Label4" runat="server" Text="Please enter the name of an element/attribute to search: "></asp:Label>
                <asp:TextBox ID="searchNodeInput" runat="server" Width="310px"></asp:TextBox>
                <asp:Button ID="searchButton" runat="server" OnClick="searchButton_Click" Text="Search!" />
            </p>
            <p>
                <asp:TextBox ID="searchOutput" runat="server" Height="340px" TextMode="MultiLine" Width="888px"></asp:TextBox>
            </p>
        </div>
    </div>

</asp:Content>
